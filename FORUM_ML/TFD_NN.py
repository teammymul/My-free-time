import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
import tensorflow as tf
import matplotlib.pyplot as plt
import seaborn as sns

# 🟢 โหลดข้อมูล
data = pd.read_csv("C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\Data_SAP_SMOTE_30.csv")

# 🟢 แยกฟีเจอร์และเป้าหมาย
X = data.drop('TFD', axis=1)  # แทนชื่อคอลัมน์ของเป้าหมาย
y = data['TFD']

# 🟢 แบ่งข้อมูลเป็น train/test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 🟢 ปรับขนาดข้อมูลด้วย StandardScaler
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 🟢 สร้างโมเดล Neural Network
model = tf.keras.Sequential([
    tf.keras.layers.Dense(64, activation='relu', input_shape=(X_train.shape[1],)),
    tf.keras.layers.Dense(32, activation='relu'),
    tf.keras.layers.Dense(16, activation='relu'),
    tf.keras.layers.Dense(1, activation='sigmoid')  # สำหรับปัญหาจำแนกประเภท 2 คลาส
])

# 🟢 คอมไพล์โมเดล
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# 🟢 ฝึกสอนโมเดล
history = model.fit(X_train, y_train, epochs=30, batch_size=32, validation_data=(X_test, y_test))

# 🟢 ประเมินผลโมเดล
loss, accuracy = model.evaluate(X_test, y_test)
print(f'\n✅ Accuracy on test data: {accuracy:.4f}')

# 🟢 ทำนายผล
y_pred = (model.predict(X_test) > 0.5).astype("int32")

# 🟢 Confusion Matrix
conf_matrix = confusion_matrix(y_test, y_pred)
print("\nConfusion Matrix:")
print(conf_matrix)

# 🔥 รายงานผลเพิ่มเติม
print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# 🟢 แสดงผล Confusion Matrix
plt.figure(figsize=(6, 4))
sns.heatmap(conf_matrix, annot=True, cmap='Blues', fmt='d', xticklabels=[0, 1], yticklabels=[0, 1])
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix')
plt.show()

# 🟢 แสดงกราฟการฝึกสอน
plt.figure(figsize=(8, 5))
plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
plt.title('Model Accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.legend()
plt.show()
