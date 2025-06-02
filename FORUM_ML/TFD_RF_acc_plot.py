import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import log_loss, accuracy_score

# โหลดข้อมูล
df = pd.read_csv("C:\\Users\\surfa\\OneDrive\\Desktop\\Forum\\Data\\data_augmented_TFD_balanced_350.csv")

# แยก Features และ Target
X = df.drop('TFD', axis=1)
y = df['TFD']

# แบ่งข้อมูลเป็น Train/Test (80% Train, 20% Test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, stratify=y, random_state=42)

# จำนวนต้นไม้ที่จะทดสอบ (แทน epochs)
n_trees = np.arange(1, 201, 1)  # ทดลองตั้งแต่ 1 ถึง 200 ต้น เพิ่มขึ้นทีละ 10

train_accs, test_accs = [], []
train_losses, test_losses = [], []

for n in n_trees:
    rf_model = RandomForestClassifier(n_estimators=n, random_state=42, n_jobs=-1)
    rf_model.fit(X_train, y_train)
    
    # คำนวณ Loss และ Accuracy
    train_acc = accuracy_score(y_train, rf_model.predict(X_train))
    test_acc = accuracy_score(y_test, rf_model.predict(X_test))
    train_loss = log_loss(y_train, rf_model.predict_proba(X_train))
    test_loss = log_loss(y_test, rf_model.predict_proba(X_test))
    
    train_accs.append(train_acc)
    test_accs.append(test_acc)
    train_losses.append(train_loss)
    test_losses.append(test_loss)

# พล็อต Accuracy
plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
sns.lineplot(x=n_trees, y=train_accs, label="Train Accuracy", marker="o")
sns.lineplot(x=n_trees, y=test_accs, label="Test Accuracy", marker="o")
plt.xlabel("Number of Trees (n_estimators)")
plt.ylabel("Accuracy")
plt.title("Accuracy vs. Number of Trees")
plt.legend()

# พล็อต Loss
plt.subplot(1, 2, 2)
sns.lineplot(x=n_trees, y=train_losses, label="Train Loss", marker="o")
sns.lineplot(x=n_trees, y=test_losses, label="Test Loss", marker="o")
plt.xlabel("Number of Trees (n_estimators)")
plt.ylabel("Log Loss")
plt.title("Loss vs. Number of Trees")
plt.legend()

plt.tight_layout()
plt.show()
