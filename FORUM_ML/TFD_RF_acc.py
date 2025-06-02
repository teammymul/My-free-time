import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split, StratifiedKFold, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# 📥 โหลดข้อมูล
file_path = "C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\Data_TFD_SMOTE_90.csv"  # เปลี่ยนเป็นพาธไฟล์ที่ถูกต้อง
df = pd.read_csv(file_path)

# 🏷️ แยก Features และ Target
X = df.drop('TFD', axis=1)
y = df['TFD']

# ✂️ แบ่งข้อมูล train-test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, stratify=y, random_state=42)

# 🔎 ทำการ Standardize ข้อมูล
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 🎯 ตั้งค่าช่วงของพารามิเตอร์สำหรับ Grid Search
param_grid = {
    'n_estimators': [100, 150, 200],
    'max_depth': [5, 7, 9],   
    'min_samples_split': [5, 10],  
    'min_samples_leaf': [5, 10],  
    'max_features': ['sqrt', 'log2', None],  
    'bootstrap': [True],
    'class_weight': ['balanced', 'balanced_subsample']
}

# 🎯 ใช้ StratifiedKFold เพื่อแบ่งข้อมูลแบบสมดุล
skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

# 🚀 สร้างโมเดลพื้นฐาน
rf_model = RandomForestClassifier(random_state=42)

# 🚀 ใช้ Grid Search CV โดยให้ Accuracy เป็นตัวเลือกพารามิเตอร์ที่ดีที่สุด
grid_search = GridSearchCV(
    estimator=rf_model,
    param_grid=param_grid,
    cv=skf,
    scoring='accuracy',  # ใช้ Accuracy แทน F1-score
    n_jobs=-1,
    verbose=2
)

# 🚀 ฝึกโมเดล
grid_search.fit(X_train, y_train)

# 🎯 พิมพ์ค่าพารามิเตอร์ที่ดีที่สุด
print("\nBest Parameters:")
print(grid_search.best_params_)

# ✅ ใช้โมเดลที่ดีที่สุด
best_model = grid_search.best_estimator_

# 🚀 ทำนายผล
y_pred_train = best_model.predict(X_train)
y_pred_test = best_model.predict(X_test)

# 🎯 ประเมินผล
train_acc = accuracy_score(y_train, y_pred_train)
test_acc = accuracy_score(y_test, y_pred_test)
cv_acc = grid_search.best_score_

print(f"\nTrain Accuracy: {train_acc:.4f}")
print(f"Test Accuracy: {test_acc:.4f}")
print(f"CV Accuracy: {cv_acc:.4f}")

# 🎯 แสดง Classification Report และ Confusion Matrix
print("\nClassification Report (Test Set):")
print(classification_report(y_test, y_pred_test))

print("\nConfusion Matrix (Test Set):")
print(confusion_matrix(y_test, y_pred_test))
