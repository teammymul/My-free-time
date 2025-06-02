import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split, RandomizedSearchCV, GridSearchCV
from sklearn.metrics import accuracy_score, log_loss
from scipy.stats import randint
from sklearn.metrics import roc_curve, auc




# 🔹 โหลดข้อมูล
df = pd.read_csv("C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\data_augmented_TFD_balanced_350.csv")

# 🔹 แยก Features และ Target
X = df.drop('TFD', axis=1)
y = df['TFD']

# 🔹 แบ่งข้อมูลเป็น Train/Test (80% Train, 20% Test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, stratify=y, random_state=42)

# 🔹 กำหนดพารามิเตอร์ที่ต้องการสุ่ม
param_dist = {
    'n_estimators': randint(50, 200),  # จำนวนต้นไม้
    'max_depth': [None, 10, 20, 30, 40],  # ความลึกของต้นไม้
    'min_samples_split': [2, 5, 10],  # จำนวนตัวอย่างขั้นต่ำที่ต้องมีเพื่อแบ่ง node
    'min_samples_leaf': [1, 2, 4],  # จำนวนตัวอย่างขั้นต่ำในใบไม้
    'max_features': ['sqrt', 'log2'],  # จำนวน feature ที่ใช้แยก node
    'bootstrap': [True, False]  # ใช้ bootstrap หรือไม่
}

# 🔹 สร้างโมเดล RandomForest
rf = RandomForestClassifier(random_state=42, n_jobs=-1)

# 🔹 ใช้ RandomizedSearchCV เพื่อสุ่มหาค่าที่ดีที่สุด
random_search = RandomizedSearchCV(rf, param_distributions=param_dist, 
                                   n_iter=20, cv=5, scoring='accuracy', 
                                   random_state=42, n_jobs=-1, verbose=1)

# 🔹 เทรนโมเดล
random_search.fit(X_train, y_train)

# 🔹 แสดงค่าที่ดีที่สุดจาก RandomizedSearchCV
best_params_random = random_search.best_params_
print("Best Parameters from Randomized Search:", best_params_random)
print("Best Accuracy from Randomized Search:", random_search.best_score_)

# 🔹 ใช้ค่าที่ดีที่สุดจาก RandomizedSearchCV มา Fine-Tune ด้วย GridSearchCV
param_grid = {
    'n_estimators': [best_params_random['n_estimators'] - 25, best_params_random['n_estimators'], best_params_random['n_estimators'] + 25],
    'max_depth': [best_params_random['max_depth'] - 10 if best_params_random['max_depth'] else None, best_params_random['max_depth'], best_params_random['max_depth'] + 10 if best_params_random['max_depth'] else None],
    'min_samples_split': [max(2, best_params_random['min_samples_split'] - 1), best_params_random['min_samples_split'], best_params_random['min_samples_split'] + 1],
    'min_samples_leaf': [max(1, best_params_random['min_samples_leaf'] - 1), best_params_random['min_samples_leaf'], best_params_random['min_samples_leaf'] + 1],
    'max_features': [best_params_random['max_features']],
    'bootstrap': [best_params_random['bootstrap']]
}

# 🔹 ใช้ GridSearchCV เพื่อหาค่าที่ดีที่สุด
grid_search = GridSearchCV(rf, param_grid, cv=5, scoring='accuracy', n_jobs=-1, verbose=1)

# 🔹 เทรนโมเดล
grid_search.fit(X_train, y_train)

# 🔹 แสดงค่าที่ดีที่สุดจาก GridSearchCV
best_params_grid = grid_search.best_params_
print("Best Parameters from Grid Search:", best_params_grid)
print("Best Accuracy from Grid Search:", grid_search.best_score_)

# 🔹 เทรนโมเดลด้วยพารามิเตอร์ที่ดีที่สุด
final_model = RandomForestClassifier(**best_params_grid, random_state=42, n_jobs=-1)
final_model.fit(X_train, y_train)

# 🔹 ทดสอบโมเดล
y_pred_train = final_model.predict(X_train)
y_pred_test = final_model.predict(X_test)

# 🔹 คำนวณ Accuracy และ Log Loss
train_acc = accuracy_score(y_train, y_pred_train)
test_acc = accuracy_score(y_test, y_pred_test)
train_loss = log_loss(y_train, final_model.predict_proba(X_train))
test_loss = log_loss(y_test, final_model.predict_proba(X_test))

# 🔹 แสดงผลลัพธ์
print(f"\n✅ Final Train Accuracy: {train_acc:.4f}")
print(f"✅ Final Test Accuracy: {test_acc:.4f}")
print(f"✅ Final Train Log Loss: {train_loss:.4f}")
print(f"✅ Final Test Log Loss: {test_loss:.4f}")

# 🔹 คำนวณค่าความน่าจะเป็นของคลาส 1 (TFD = 1)
y_prob_train = final_model.predict_proba(X_train)[:, 1]
y_prob_test = final_model.predict_proba(X_test)[:, 1]

# 🔹 คำนวณค่า FPR, TPR สำหรับ Train และ Test
fpr_train, tpr_train, _ = roc_curve(y_train, y_prob_train)
fpr_test, tpr_test, _ = roc_curve(y_test, y_prob_test)

# 🔹 คำนวณ AUC
auc_train = auc(fpr_train, tpr_train)
auc_test = auc(fpr_test, tpr_test)

# 🔹 Plot ROC Curve
plt.figure(figsize=(8, 6))
plt.plot(fpr_train, tpr_train, label=f'Train ROC (AUC = {auc_train:.4f})', linestyle='--')
plt.plot(fpr_test, tpr_test, label=f'Test ROC (AUC = {auc_test:.4f})', color='darkorange')
plt.plot([0, 1], [0, 1], linestyle="--", color="gray")  # เส้นไดอากอนัล
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel("False Positive Rate (FPR)")
plt.ylabel("True Positive Rate (TPR)")
plt.title("Receiver Operating Characteristic (ROC) Curve")
plt.legend()
plt.grid(True)
plt.show()