import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score

file_path = "C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\Data_TFD_SMOTE_Added_50.csv"  # แก้เป็น path ของคุณ
df = pd.read_csv(file_path)

X = df.drop(columns=['TFD']) 
y = df['TFD'] 

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, stratify=y, random_state=42)

rf_model = RandomForestClassifier(random_state=42, class_weight='balanced')
rf_model.fit(X_train, y_train)

y_pred = rf_model.predict(X_test)

test_acc = accuracy_score(y_test, y_pred)

cm = confusion_matrix(y_test, y_pred)

plt.figure(figsize=(6, 5))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["No TFD", "TFD"], yticklabels=["No TFD", "TFD"])
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title(f"Confusion Matrix (Test Acc: {test_acc:.4f})")
plt.show()

print(f"Confusion Matrix:\n{cm}")
print(f"Test Accuracy: {test_acc:.4f}")
