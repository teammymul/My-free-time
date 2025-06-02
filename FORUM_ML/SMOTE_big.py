import pandas as pd
from imblearn.over_sampling import SMOTE

# โหลดข้อมูล
file_path = "C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\Data_SAP_SMOTE_30.csv"  # แก้เป็น path ที่ถูกต้อง
df = pd.read_csv(file_path)

# แยก Features และ Target
X = df.drop('Sap', axis=1)
y = df['Sap']

# ใช้ SMOTE เพื่อเพิ่มข้อมูลเป็น 350 รายการ
smote = SMOTE(sampling_strategy=350 / len(y), random_state=42)
X_resampled, y_resampled = smote.fit_resample(X, y)

# รวมกลับเป็น DataFrame
df_resampled = pd.concat([pd.DataFrame(X_resampled, columns=X.columns), pd.DataFrame(y_resampled, columns=['TFD'])], axis=1)

# บันทึกไฟล์ใหม่
df_resampled.to_csv("C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\Data\\DataData_SAP_SMOTE_350.csv", index=False)

print(f"จำนวนข้อมูลหลัง SMOTE: {len(df_resampled)}")
print(df_resampled['Sap'].value_counts())
