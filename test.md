# บทนำ
หลายๆ คนอาจจะเคยได้ยิน/รู้จัก Fast Fourier Transform มาบ้าง ในบทความนี้จะเน้นการใช้ Fast Fourier Transform ใน Competitive Programming นะครับ

# ประโยชน์
โดยปกติ การคูณพหุนามสามารถทำได้ง่ายใน ![](https://latex.codecogs.com/svg.latex?\inline&space;O(n^2)) แต่มีอัลกอที่มีประสิทธิภาพที่สามารถทำได้เพียง ![](https://latex.codecogs.com/svg.latex?\inline&space;O(n&space;\log&space;n)) เท่านั้น

# Fast Fourier Transform
## Coefficient Representation
พหุนาม 
![](https://latex.codecogs.com/svg.latex?\inline&space;P&space;=&space;a_0x^0&space;&plus;&space;a_1x^1&space;&plus;&space;a_2x^2&space;&plus;&space;\dotsc&space;&plus;&space;a_{n-1}x^{n-1}) 
ที่มี degree `n-1` สามารถเขียนในรูป 
![](https://latex.codecogs.com/svg.latex?\inline&space;C&space;=&space;\{a_0,&space;a_1,&space;a_2,&space;\dotsc,&space;a_{n-1}\})
## Point-Value Representation
พหุนาม $P = a_0x^0 + a_1x^1 + a_2x^2 + \dotsc + a_{n-1}x^{n-1}$ ที่มี degree $n-1$ สามารถเขียนในรูป $S = {(x_0, y_0), (x_1, y_1), (x_2, y_2), ..., (x_{n-1}, y_{n-1})}$ โดยที่ $x_0 \neq x_1 \neq x_2 \neq \dotsc \neq x_{n-1}$ และ $y_0 = P(x_0), y_1 = P(x_1), y_2 = P(x_2), \dotsc, y_{n-1} = P(x_{n-1})$
