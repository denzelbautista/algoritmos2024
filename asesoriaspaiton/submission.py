def pregunta_1( dia : int, mes: int) ->str: 
    """
    Halla el nombre de la estacion del anio en que una persona nacio
    Parametros:
        dia (int) :  Es el dia en que nacio
        mes (int) :  Es el numero del mes en que nacio
    Retorna:
        str : la cadena indica en nombre del mes en que nacio, de acuerdo a la tabla
    
        |===========|==============|===============|
        |  Estación |    Inicio    |      Fin      |
        |===========|==============|===============|
        | Verano    | 21 Diciembre | 20 Marzo      |
        | Otonno    | 21 Marzo     | 21 Junio      |
        | Invierno  | 22 Junio     | 22 Setiembre  |
        | Primavera | 23 Setiembre | 20 Diciembre  |
        |===========|==============|===============|
    """
    estacion = ""
    if (mes == 12 and dia>=21) or (mes == 1) or (mes == 2) or (mes == 3 and dia <= 20): 
        estacion = "Verano"
    elif (mes == 3 and dia >= 21) or (mes == 4) or (mes == 5) or (mes == 6 and dia <=21):
        estacion = "Otonno"
    elif ( mes ==6 and dia >=22 ) or (mes == 7 ) or (mes == 8) or (mes == 9 and dia <=22):
        estacion = "Invierno"
    elif (mes == 9 and dia >= 23) or (mes == 10) or (mes == 11) or (mes == 12 and dia<=20):
        estacion = "Primavera"
    
    return estacion
   


def pregunta_2( n1 :  int, n2: int) ->int:
    """
    Halla la suma de todos los numeros desde n1 hasta n2, que cumplan al menos una de las condiciones
    Parametros:
        n1 (int) : es el primer numero
        n2 (int) : es el segundo numero
    Retorna:
        int : es la suma 
    """
    suma = 0
    for numero in range(n1, n2 + 1):
        if (numero % 5 == 0 and numero % 7 == 0) or (numero % 3 == 0 and numero % 4 == 0):
            suma += numero
    return suma 

def pregunta_3(numero : int)-> int:
    """
    Determina la suma de los divisores menores del numero
    Parametros:
        numero (int) : un numero entero 
    Retorna:
        int : Es la  suma de los divisores menores del numero 
    """
    suma_divisores = 0
    for divisor in range(1, numero):
        if numero % divisor == 0:
            suma_divisores += divisor
    return suma_divisores

      

def pregunta_4( numeroDeTerminos :  int) -> int: 
    """
    Halla la sumatoria de los terminos de la serie
    Parametros:
    	numeroDeTerminos (int) :  Indica la cantidad de terminos
    Retorna:
    	 int :  La suma de los terminos de la serie
    """
    suma = 0
    for i in range(1, numeroDeTerminos + 1):
        suma += i ** 3
    return suma
   