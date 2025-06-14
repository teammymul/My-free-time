import pandas as pd
import numpy as np

# โหลดข้อมูล
df = pd.read_csv("C:\\Users\\surfa\\Downloads\\Book1.csv")

# สร้างเมทริกซ์ผลต่าง B_j - A_i
A = df['A'].values
B = df['B'].values
n = len(A)

# คำนวณผลต่างแบบเมทริกซ์
diff_matrix = B.reshape(1, n) - A.reshape(n, 1)
diff_flat = diff_matrix.flatten()  # 46,656 ค่า

# สร้างตารางความถี่
diff_freq = pd.Series(diff_flat).value_counts().sort_index()

# Export: ค่าผลต่างทั้งหมด
all_diff_df = pd.DataFrame({'difference': diff_flat})
all_diff_df.to_csv("all_differences.csv", index=False)

# Export: ความถี่ของค่าผลต่าง
diff_freq.to_csv("diff_frequency.csv", header=["frequency"])

print("บันทึกไฟล์แล้ว:")
print("- all_differences.csv (ผลต่างทั้งหมด)")
print("- diff_frequency.csv (ตารางความถี่)")
