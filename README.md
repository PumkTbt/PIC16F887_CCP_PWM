# PIC16F887_CCP_PWM
![image](https://github.com/PumkTbt/PIC16F887_CCP_PWM/assets/124877073/e20b433b-5583-4538-9822-8135122f1cee)

Nhấn SW0: LCD hiển thị: line 0: họ và tên sinh viên (chữ có dấu) line 1: lớp - MSSV
Nhấn SW1: Xuất xung PWM có f = 8KHz, D = 60% và LCD hiển thị:
line 0: MODUL CCP; line 1: PWM-f=8KHz-D=60%

Phân tích
Để tạo xung PWM khi có: 𝑓𝑃𝑊𝑀 = 8𝐾𝐻𝑧 𝐷 = 60% . Tại chân RC1(CCP2), ta tiến hành:
Chọn Pre = 1
𝑇𝑃𝑊𝑀 = 1
𝑓𝑃𝑊𝑀
=
1
8000
= 125𝜇𝑠
- Ta có :
𝑇𝑃𝑊𝑀 = (𝑃𝑅2 + 1). 4. 1
𝑓𝑜𝑠𝑐
. 𝑃𝑟𝑒
⇒ 𝑃𝑅2 = 124
- Với CCP2: D% = 60%
⇒ 𝑃𝑊𝑀 =
𝐷. 𝑇𝑃𝑊𝑀
100 =
60.125
100 = 75𝜇𝑠
- Từ công thức:
𝑃𝑊 = (𝐶𝐶𝑃𝑅𝑥𝐿: 𝐶𝑃𝑃𝑥𝐶𝑂𝑁 < 5: 4 >). 1
𝑓𝑜𝑠𝑐 . 𝑃𝑟𝑒
- Đặt E = (𝐶𝐶𝑃𝑅𝑥𝐿: 𝐶𝑃𝑃𝑥𝐶𝑂𝑁 < 5: 4 >) suy ra:
E = 300
CCP2L = E/4 = 75
- 𝐶𝑃𝑃𝑥𝐶𝑂𝑁 < 5: 4 > = 𝐸%4 = 0 suy ra giá trị từ bảng TT(hình 4.1) ta có:
𝐷𝐶2𝐵1 = 0 𝑣à 𝐷𝐶2𝐵0 = 0
𝐶𝑃𝑃𝑥𝐶𝑂𝑁
< 5: 4 >
𝐷𝐶𝑋𝐵1 𝐷𝐶𝑋𝐵0
0 0 0
1 0 1
2 1 0
3 1 1
Hình 4.1. Bảng giá trị
 Đối với hiển thị chữ tiếng việt có dấu lên LCD thì chúng ta cần sử dụng
cgram:
cgram_dat[] = {
10, 21, 0, 30, 1, 31, 17, 31,
2, 4, 0, 30, 1, 31, 17, 31,
0, 17, 17, 11, 6, 12, 26, 0,
0x99,};
- Với lần lượt các chữ cái có dấu là những mảng số như sau:
+ {10, 21, 0, 30, 1, 31, 17, 31}: Chữ “ ầ”
+ {2, 4, 0, 30, 1, 31, 17, 31}: Chữ “á”
+ {0, 17, 17, 11, 6, 12, 26, 0}: Chữ “ỵ”

  ![image](https://github.com/PumkTbt/PIC16F887_CCP_PWM/assets/124877073/d7d69188-f1e6-4e0b-a45b-b24632b25bda)

  ![image](https://github.com/PumkTbt/PIC16F887_CCP_PWM/assets/124877073/11dbd210-00b2-4748-992b-74a0ed2128c7)

  ![image](https://github.com/PumkTbt/PIC16F887_CCP_PWM/assets/124877073/0e8916ec-475c-4c5e-9be0-006289e6e71b)

  ![image](https://github.com/PumkTbt/PIC16F887_CCP_PWM/assets/124877073/73465601-f1dd-4884-b9d3-0239ddfa56b0)

Quan sát thấy xung PWM đầu ra đúng với yêu cầu là 8KHz. Dạng sóng xung đầu ra là dạng sóng vuông, có tần số 8KHz.




