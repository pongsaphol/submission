# Fast Fourier Transform

# บทนำ
หลายๆ คนอาจจะเคยได้ยิน/รู้จัก Fast Fourier Transform มาบ้าง ในบทความนี้จะเน้นการใช้ Fast Fourier Transform ใน Competitive Programming นะครับ

# ประโยชน์
โดยปกติ การคูณพหุนามสามารถทำได้ง่ายใน `O(n^2)` แต่มีอัลกอที่มีประสิทธิภาพที่สามารถทำได้เพียง $$O(n log n)$$ เท่านั้น
![](https://latex.codecogs.com/svg.latex?\dpi{300}&space;P=a_0x^0&plus;a_1x^1&plus;a_2x^2&plus;...&plus;a_{n-1}x^{n-1})
# FFT
## Coefficient Representation
พหุนาม $P = a_0x^0 + a_1x^1 + a_2x^2 + \dotsc + a_{n-1}x^{n-1}$ ที่มี degree $n-1$ สามารถเขียนในรูป $C = {a_0, a_1, a_2, \dotsc, a_{n-1}}$
## Point-Value Representation
พหุนาม $P = a_0x^0 + a_1x^1 + a_2x^2 + \dotsc + a_{n-1}x^{n-1}$ ที่มี degree $n-1$ สามารถเขียนในรูป $S = {(x_0, y_0), (x_1, y_1), (x_2, y_2), ..., (x_{n-1}, y_{n-1})}$ โดยที่ $x_0 \neq x_1 \neq x_2 \neq \dotsc \neq x_{n-1}$ และ $y_0 = P(x_0), y_1 = P(x_1), y_2 = P(x_2), \dotsc, y_{n-1} = P(x_{n-1})$
