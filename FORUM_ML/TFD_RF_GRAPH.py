import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, log_loss

# 🔹 โหลดข้อมูล
df = pd.read_csv("C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\data_augmented_TFD_balanced_350.csv")

# 🔹 แยก Features และ Target
X = df.drop('TFD', axis=1)
y = df['TFD']

# 🔹 แบ่งข้อมูลเป็น Train/Test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, stratify=y, random_state=42)

# 🔹 ลิสต์เก็บผลลัพธ์
n_trees = np.arange(5, 1000, 10)  # กำหนดจำนวนต้นไม้ (n_estimators)
train_acc = []
test_acc = []
train_loss = []
test_loss = []

# 🔹 เทรนโมเดลด้วยจำนวนต้นไม้ที่แตกต่างกัน
for n in n_trees:
    model = RandomForestClassifier(n_estimators=n, random_state=42, n_jobs=-1)
    model.fit(X_train, y_train)
    
    # ทำนายค่า
    y_train_pred = model.predict(X_train)
    y_test_pred = model.predict(X_test)
    
    # คำนวณ Accuracy
    train_acc.append(accuracy_score(y_train, y_train_pred))
    test_acc.append(accuracy_score(y_test, y_test_pred))
    
    # คำนวณ Log Loss
    train_loss.append(log_loss(y_train, model.predict_proba(X_train)))
    test_loss.append(log_loss(y_test, model.predict_proba(X_test)))

# 🔹 สร้างกราฟ
fig, axes = plt.subplots(1, 2, figsize=(12, 5))

# 🔹 Accuracy Graph
axes[0].plot(n_trees, train_acc, label="Train Accuracy", marker='o', color='blue')
axes[0].plot(n_trees, test_acc, label="Test Accuracy", marker='s', color='orange')
axes[0].set_xlabel("Number of Trees (n_estimators)")
axes[0].set_ylabel("Accuracy")
axes[0].set_title("Accuracy vs. Number of Trees")
axes[0].legend()
axes[0].grid(True)

# 🔹 Log Loss Graph
axes[1].plot(n_trees, train_loss, label="Train Loss", marker='o', color='blue')
axes[1].plot(n_trees, test_loss, label="Test Loss", marker='s', color='orange')
axes[1].set_xlabel("Number of Trees (n_estimators)")
axes[1].set_ylabel("Log Loss")
axes[1].set_title("Loss vs. Number of Trees")
axes[1].legend()
axes[1].grid(True)

plt.tight_layout()
plt.show()
