def ralston_h_variavel(f, x0, y0, n,b, x_values):
    # b = 1 => metodo = euler_mid
    # b = 1/2 => metodo = heun
    # b = 2/3 => metodo = ralston
     vals = []
     for i in range(n):
        if i == 0:
            h = x_values[0] - x0
        else:
            h = x_values[i] - x_values[i-1]
        m1 = f(x0, y0)
        m2 = f(x0 + 3/4 *h, y0 + m1 *3/4 * h )
        y0 += (1 *m1 + m2*2)*h/3
        x0 += h
        vals.append([x0, y0])
     return vals

#Q10 Prova:
def f(x,y):
    return y*(2-x)+x+1

n = 10
b = 2/3
x_values = [0.612, 0.827, 1.046, 1.313, 1.512, 1.938, 2.155, 2.366, 2.562, 2.875]

x0, y0 = 0.374, 0.391

e = ralston_h_variavel(f,x0,y0,n, b, x_values)
for xi, yi in e:
    print(xi, yi)