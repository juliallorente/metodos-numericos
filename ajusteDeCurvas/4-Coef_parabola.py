import numpy as np
# import scipy as sp

def best_poly (x, y, k):
    n = len(x)
    if n <= k:
        raise ValueError('O número de pontos deve ser maior que k (o grau do polinônmio)')

    somas = {}
    somas[0] = n
    for n in range(1, 2*k + 1):
        somas[n] = sum(xi ** n for xi in x)
    A = []
    B = []
    for i in range (k + 1):
        row = []
        for j in range(k + 1):
            row.append(somas[i + j])
        A.append(row)
        if i == 0:
            B.append(sum(y))
        else:
            B.append(sum(xi ** i * yi for xi, yi in zip(x,y)))
    return np.linalg.solve(A, B)

x = [0.0259, 0.1815, 0.3278, 0.4201, 0.4662, 0.663, 0.7105, 0.8713, 1.0205, 1.1016, 1.2725, 1.3142, 1.4663, 1.5724, 1.6768, 1.7604, 1.9448, 2.0108, 2.1007, 2.2929, 2.3731, 2.4503, 2.6143, 2.7277, 2.8925, 2.9181, 3.0683, 3.1654, 3.3299, 3.4409, 3.5625, 3.6912, 3.8311, 3.9378, 4.0663, 4.1591, 4.2566, 4.3471, 4.439, 4.6142, 4.6856, 4.8698, 4.9229, 5.0332, 5.2273, 5.2564, 5.4474, 5.4905, 5.6676, 5.7927, 5.8393, 5.9616, 6.1025, 6.1912, 6.3704, 6.4477, 6.6039, 6.6488, 6.7814, 6.9425, 7.0913, 7.1175, 7.3094, 7.378, 7.539, 7.6575, 7.7391, 7.8553, 7.9705, 8.0712, 8.2024, 8.2724, 8.4653, 8.5499, 8.6807, 8.7483, 8.8941, 9.0232, 9.1513, 9.2369, 9.3986, 9.4482, 9.562, 9.7253, 9.789, 9.9307]
y = [6.598, 6.7031, 5.7256, 5.5743, 5.4253, 5.0509, 5.6705, 5.4076, 5.7757, 6.0306, 4.8289, 4.9828, 5.5329, 4.9567, 4.785, 4.7012, 4.9361, 4.6076, 4.3431, 4.7033, 4.648, 4.2226, 4.2829, 4.282, 4.2601, 4.2847, 4.1747, 5.0217, 4.0454, 3.9252, 3.876, 3.7598, 3.2076, 3.7716, 3.144, 3.9562, 4.5728, 4.3217, 3.6615, 3.7039, 3.7252, 3.6685, 3.6268, 3.843, 3.1836, 3.6659, 3.5324, 4.0111, 4.0531, 4.5431, 3.5858, 3.8041, 4.0087, 3.5768, 4.3755, 3.6728, 3.8636, 4.5689, 3.9216, 2.7248, 3.7642, 3.8236, 4.1297, 4.0499, 4.2993, 3.9958, 4.2773, 4.1821, 5.506, 4.127, 4.8534, 4.3967, 4.221, 4.2725, 4.3631, 4.5649, 3.5828, 4.4276, 4.8095, 4.3469, 4.7165, 5.1778, 4.8916, 4.2439, 4.954, 5.0529]
a0, a1, a2 = best_poly(x, y, 2)

print(f'{a0 = } , {a1 = }, {a2 = }')