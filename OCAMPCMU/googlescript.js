function doGet(e) {
  const studentId = e.parameter.id;
  if (!studentId) {
    return ContentService.createTextOutput(JSON.stringify({ error: "กรุณาใส่รหัสนักเรียน เช่น ?id=65001" }))
      .setMimeType(ContentService.MimeType.JSON);
  }

  const sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName("ชีต1");
  if (!sheet) {
    return ContentService.createTextOutput(JSON.stringify({ error: "ไม่พบชีต กรุณาตรวจสอบชื่อชีตใน Google Sheet" }))
      .setMimeType(ContentService.MimeType.JSON);
  }

  const data = sheet.getDataRange().getValues();
  const rows = data.slice(1);

  for (let i = 0; i < rows.length; i++) {
    if (rows[i][0].toString() === studentId) {
      const result = {
        student_id: rows[i][0],
        name: rows[i][1],       
        score: rows[i][2],      
        status: rows[i][3],     
        branch: rows[i][4]      
      };
      return ContentService.createTextOutput(JSON.stringify(result))
        .setMimeType(ContentService.MimeType.JSON);
    }
  }

  return ContentService.createTextOutput(JSON.stringify({ error: "ไม่พบรหัสนักเรียนนี้ในระบบ" }))
    .setMimeType(ContentService.MimeType.JSON);
}
