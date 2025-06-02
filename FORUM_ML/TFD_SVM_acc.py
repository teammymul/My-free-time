import pandas as pd
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# 📥 โหลดข้อมูล
file_path = "C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\Data_TFD_SMOTE_90.csv"  # เปลี่ยนชื่อไฟล์ตามที่ใช้งาน
df = pd.read_csv(file_path)

# 🏷️ แยก Features และ Target
X = df.drop('TFD', axis=1)  # 'TFD' คือ target ที่ต้องการพยากรณ์
y = df['TFD']

# ✂️ แบ่งข้อมูล train-test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 🔎 Standardize ข้อมูล
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 🎯 กำหนดค่าพารามิเตอร์ที่ต้องการทดสอบ
param_grid = {
    'C': [0.1, 1, 10, 100],  
    'gamma': ['scale', 'auto', 0.01, 0.1, 1],  
    'kernel': ['linear', 'rbf', 'poly', 'sigmoid']  
}

# 🔍 ใช้ GridSearchCV ค้นหาค่าที่ดีที่สุด
grid_search = GridSearchCV(SVC(random_state=42), param_grid, cv=5, scoring='accuracy', n_jobs=-1)
grid_search.fit(X_train, y_train)

# ✅ แสดงค่าพารามิเตอร์ที่ดีที่สุด
print("Best Parameters:", grid_search.best_params_)
print("Best Training Accuracy:", grid_search.best_score_)

# 🚀 ทดสอบโมเดลที่ดีที่สุด
best_svm = grid_search.best_estimator_
y_pred = best_svm.predict(X_test)

# 📊 ประเมินผล
accuracy = accuracy_score(y_test, y_pred)
confusion = confusion_matrix(y_test, y_pred)
report = classification_report(y_test, y_pred)

print(f'Accuracy on Test Set: {accuracy:.4f}')
print('Confusion Matrix:')
print(confusion)
print('Classification Report:')
print(report)
