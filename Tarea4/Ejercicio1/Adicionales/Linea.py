import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Datos de ejemplo
tamanio_entrada = np.array([25, 50, 100, 200, 400, 600, 1600])
tiempo_computo = np.array([0.0031433,0.0098299,0.0338384,0.1141493,0.4003192,1.0640261,6.6783769])

# Definir la función de ajuste (ejemplo lineal)
def lineal(x, a, b):
    return a * x + b

# Ajustar los datos a la función lineal
params, _ = curve_fit(lineal, tamanio_entrada, tiempo_computo)

# Generar valores ajustados
ajuste_lineal = lineal(tamanio_entrada, *params)

# Calcular el valor de R^2
ss_res = np.sum((tiempo_computo - ajuste_lineal) ** 2)
ss_tot = np.sum((tiempo_computo - np.mean(tiempo_computo)) ** 2)
r_squared = 1 - (ss_res / ss_tot)

# Crear la gráfica
plt.scatter(tamanio_entrada, tiempo_computo, label='Datos')
plt.plot(tamanio_entrada, ajuste_lineal, color='red', label=f'Ajuste lineal: $y = {params[0]:.6f}x + {params[1]:.6f}$\n$R^2 = {r_squared:.6f}$')
plt.xlabel('Tamaño de entrada')
plt.ylabel('Tiempo de cómputo (s)')
plt.legend()
plt.show()
