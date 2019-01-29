# บทนำ
หลายๆ คนอาจจะเคยได้ยิน/รู้จัก Fast Fourier Transform มาบ้าง ในบทความนี้จะเน้นการใช้ Fast Fourier Transform ใน Competitive Programming นะครับ

# ประโยชน์
โดยปกติ การคูณพหุนามสามารถทำได้ง่ายใน ![](https://latex.codecogs.com/svg.latex?\inline&space;O(n^2)) แต่มีอัลกอที่มีประสิทธิภาพที่สามารถทำได้เพียง ![](https://latex.codecogs.com/svg.latex?\inline&space;O(n&space;\log&space;n)) เท่านั้น

# Fast Fourier Transform
## Coefficient Representation
พหุนาม 
![](https://latex.codecogs.com/svg.latex?\inline&space;P&space;=&space;a_0x^0&space;&plus;&space;a_1x^1&space;&plus;&space;a_2x^2&space;&plus;&space;\dotsc&space;&plus;&space;a_{n-1}x^{n-1}) ที่มี `degree n-1` สามารถเขียนในรูป 
![](https://latex.codecogs.com/svg.latex?\inline&space;C&space;=&space;\{a_0,&space;a_1,&space;a_2,&space;\dotsc,&space;a_{n-1}\})
## Point-Value Representation
พหุนาม 
![](https://latex.codecogs.com/svg.latex?\inline&space;P&space;=&space;a_0x^0&space;&plus;&space;a_1x^1&space;&plus;&space;a_2x^2&space;&plus;&space;\dotsc&space;&plus;&space;a_{n-1}x^{n-1})  
ที่มี `degree n-1` สามารถเขียนในรูป

![](https://latex.codecogs.com/svg.latex?\inline&space;S&space;=&space;\{(x_0,&space;y_0),&space;(x_1,&space;y_1),&space;(x_2,&space;y_2),&space;...,&space;(x_{n-1},&space;y_{n-1})\})
โดยที่ 
![](https://latex.codecogs.com/svg.latex?\inline&space;x_0&space;\neq&space;x_1&space;\neq&space;x_2&space;\neq&space;\dotsc&space;\neq&space;x_{n-1})
และ
![](https://latex.codecogs.com/svg.latex?\inline&space;y_0&space;=&space;P(x_0),&space;y_1&space;=&space;P(x_1),&space;y_2&space;=&space;P(x_2),&space;\dotsc,&space;y_{n-1}&space;=&space;P(x_{n-1}))
## Multiplication of polynomials
ให้ 
![](https://latex.codecogs.com/svg.latex?\inline&space;P&space;=&space;a_0x^0&space;&plus;&space;a_1x^1&space;&plus;&space;a_2x^2&space;&plus;&space;\dotsc&space;&plus;&space;a_{n-1}x^{n-1}) 
และ
![](https://latex.codecogs.com/svg.latex?\inline&space;Q&space;=&space;b_0x^0&space;&plus;&space;b_1x^1&space;&plus;&space;b_2x^2&space;&plus;&space;\dotsc&space;&plus;&space;b_{n-1}x^{n-1})
เป็นพหุนามที่มี `degree n-1`
