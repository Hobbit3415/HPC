# Parcial 03 - Song_Data
<div> 
<img src="https://user-images.githubusercontent.com/110416644/186033336-b0ce35ce-b894-4b88-8499-95562e8915f0.png" width="310" align="right"><br><br><FONT FACE="sans-serif" SIZE=4>
<b>Ciencias de la computación e Inteligencia Artificial </b>
<br>
<b>Autor: </b>
Emmanuel Mora Mosquera
<br>
<b>Correo: </b>
emmanuel.mora3415@gmail.com
 <br>
<i><b>Docente:</b></i> John Corredor
<br>
<b>Asignatura:</b> HPC
<br>
<b>Tema:</b> Parcial 03 - Song Data
<br>
</FONT>
</div>

# Resumen
La regresión lineal es una técnica paramétrica empleada en machine learning. Al ser paramétrica, antes de analizar los datos ya se conoce el número 
de parámetros o coeficientes que se van a necesitar. Por ejemplo, con una sola variable, se sabe que una línea va a contar con dos parámetros.
El modelo se expresa a través de la siguiente notación:

* **Y:** Es la variable dependiente u objetivo.
* **X:** Representa las variables explicativas, independientes o regresoras.
* **B:** Son los parámetros del modelo, los cuales miden la influencia que las variables explicativas ejercen sobre el regrediendo.

No obstante, pese a conocer los parámetros que se necesitan, es preciso elegir los que resulten más adecuados para los datos que se vayan a manejar.
Estos serán aquellos que minimicen alguna medida de error. 

Por regla general, en la regresión lineal se utiliza el error cuadrático medio. La fórmula que se usaría para una regresión lineal con una sola variable X es la siguiente: 

$y=wx+b$

Esta técnica ayuda a comprender y predecir el comportamiento de los sistemas complejos, algo muy útil a la hora de diseñar una inteligencia artificial.
También permite analizar datos experimentales, financieros y biológicos. El modelo que se crea con esta regresión es un lineal: describe las relaciones 
existentes en una variable $Y$, que se conoce como respuesta, como función de una o varias variables independientes $X$, denominadas predictores.

El siguiente repositorio contiene un modelo de regresión lineal escrito en codigo C++; Está diseñado para predecir que tan popular es una canción
con base en sus características. 

Nota
---
> Este dataset también fue trabajado en python mediante la biblioteca Scikit learn. Puede observar los resultados y un análisis más especifico
> del mismo en el siguiente enlace:
> [Notebook Python](https://colab.research.google.com/drive/1uz4szgpt4mK-E_I4U_2gqTTYpkFdEns8?usp=sharing)

# [Dataset](https://github.com/Hobbit3415/HPC/blob/main/parcial03/Dataset/song_data.csv)
## Variables del dataset
0. **song_popularity**: Variable que indica que tan popular es la canción (variable objetivo)
1. **song_duration_ms**: Variable que indica la duración en ms de la canción
2. **acousticness**: Una medida de confianza de 0,0 a 1,0 sobre si la pista es acústica. 1,0 representa una alta confianza en que la pista es acústica.
3. **danceability**: Danceability describe la idoneidad de una pista para el baile basándose en una combinación de elementos musicales como el tempo, la estabilidad del ritmo, la fuerza del compás y la regularidad general. Un valor de 0,0 es el menos bailable y 1,0 el más bailable.
4. **energy**: La energía es una medida de 0,0 a 1,0 y representa una medida perceptiva de intensidad y actividad. Por lo general, las pistas energéticas se sienten rápidas, ruidosas y con mucho ruido. Por ejemplo, el death metal tiene mucha energía, mientras que un preludio de Bach tiene una puntuación baja en la escala. Las características perceptivas que contribuyen a este atributo son el rango dinámico, el volumen percibido, el timbre, la velocidad de aparición y la entropía general.
5. **instrumentalness**: Predice si una pista no contiene voces. Los sonidos "Ooh" y "aah" se consideran instrumentales en este contexto. Las pistas de rap o de palabras habladas son claramente "vocales". Cuanto más se acerque el valor de instrumentalización a 1,0, mayor será la probabilidad de que la pista no tenga contenido vocal. Los valores superiores a 0,5 representan pistas instrumentales, pero la confianza es mayor a medida que el valor se acerca a 1,0.
6. **key**: La tonalidad musical en la se encuentra la pista. Los números enteros se asignan a los tonos utilizando la notación estándar de la clase de tono. Por ejemplo, 0 = C, 1 = C♯/D♭, 2 = D, y así sucesivamente. Si no se detecta ninguna clave, el valor es -1.
7. **liveness**: Detecta la presencia de público en la grabación. Los valores más altos de liveness representan una mayor probabilidad de que la pista haya sido interpretada en directo. Un valor superior a 0,8 proporciona una fuerte probabilidad de que la pista sea en directo.
8. **loudness**: La sonoridad general de una pista en decibelios (dB). Los valores de sonoridad se promedian en toda la pista y son útiles para comparar la sonoridad relativa de las pistas. La sonoridad es la cualidad de un sonido que es el principal correlato psicológico de la fuerza física (amplitud). Los valores suelen oscilar entre -60 y 0 db.
9. **audio_mode**: Indica la modalidad (mayor o menor) de una pista, el tipo de escala del que se deriva su contenido melódico. El mayor se representa con 1 y el menor con 0.
10. **speechiness**: La expresividad detecta la presencia de palabras habladas en una pista. Cuanto más exclusivamente hablada sea la grabación (por ejemplo, un programa de entrevistas, un audiolibro o una poesía), más se acercará a 1,0 el valor del atributo. Los valores superiores a 0,66 describen pistas que probablemente estén compuestas exclusivamente por palabras habladas. Los valores entre 0,33 y 0,66 describen pistas que pueden contener tanto música como voz, ya sea en secciones o en capas, incluyendo casos como la música rap. Los valores inferiores a 0,33 representan probablemente música y otras pistas no habladas.
11. **tempo**: El tempo global estimado de una pista en pulsaciones por minuto (BPM). En la terminología musical, el tempo es la velocidad o el ritmo de una pieza determinada y se deriva directamente de la duración media de los tiempos.
12. **time_signature**: Un compás estimado. El compás es una convención de notación para especificar cuántos tiempos hay en cada compás. El compás va de 3 a 7, indicando compases de "3/4" a "7/4".

# Conclusiones
* Gracias a que el dataset no posee columnas categoricas, trabajar con el mismo fue una tarea llevadera. Mediante las métricas que contiene es posible 
predecir que tan popular puede ser una canción ya que la duración, el tempo, que tan bailable es y su nivel de instrumentalismo al ser valores numéricos, 
pueden ser modelados mediante un modelo de regresión.
* Las columnas del dataset poseen bastantes datos outliers, es por esto que la estandarización de las mismas es importante para mejorar el proceso de 
entrenamiento del modelo. En el módelo de C++ esto se hizo mediante un StandardScaler, mientras que en Python gracias a la biblioteca de Scikit Learn es
posible utilizar el Robust Scaler el cuál, lleva a cabo esta tarea de una forma más eficiente ya que está diseñado específicamente para tratar con datos
outliers.
* El proceso de crear un modelo de regresión lineal en Python es sencillo gracias a la biblioteca SciKit Learn la cuál, cuenta con todos los métodos 
necesarios para realizar el preprocesamiento de la información, la construcción del modelo y de ser necesario, su automatización. A pesar de esto, es 
necesario destacar que todo esto conlleva un precio que, al comparar con un modelo hecho en C++, se paga en rendimiento. Cada uno tiene sus ventajas, 
pero en un entorno en el que sea necesario trabajar con grandes volúmenes de datos y se cuente con la infraestructura necesaria, trabajar estos modelos 
en python siempre será mejor puesto que no es necesario tener tanta rigurosidad en el manejo de los datos a comparación de C++
* La comparación final del modelo no fue satisfactoria debido a los problemas mencionados anteriormente. Sin embargo, ya se tenía un precedente de cómo
debería de comportarse el modelo con un set de datos diferente. La sifguiente gráfica es unaa comparación entre el modelo de regresión trabajado
anteriormente con el dataset Winedata
