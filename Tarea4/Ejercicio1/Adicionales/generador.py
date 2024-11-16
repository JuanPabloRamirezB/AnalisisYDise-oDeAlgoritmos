import random

def generar_segmentos(num_segmentos, max_coord):
    segmentos = []
    for _ in range(num_segmentos):
        x1 = random.randint(0, max_coord)
        y1 = random.randint(0, max_coord)
        x2 = random.randint(0, max_coord)
        y2 = random.randint(0, max_coord)
        segmentos.append((x1, y1, x2, y2))
    return segmentos

def guardar_segmentos_en_archivo(segmentos, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        archivo.write(f"{len(segmentos)}\n")
        for (x1, y1, x2, y2) in segmentos:
            archivo.write(f"{x1} {y1} {x2} {y2}\n")

def main():
    num_segmentos = 1600  # Puedes cambiar el número de segmentos que deseas generar
    max_coord = 620  # Puedes cambiar el valor máximo de las coordenadas
    i = 5
    for i in range(10):
        nombre_archivo = str(num_segmentos)+"lineasEj"+str(i)+".txt"  
        
        segmentos = generar_segmentos(num_segmentos, max_coord)
        guardar_segmentos_en_archivo(segmentos, nombre_archivo)
        print(f"Archivo '{nombre_archivo}' creado con {num_segmentos} segmentos de línea.")

if __name__ == "__main__":
    main()
