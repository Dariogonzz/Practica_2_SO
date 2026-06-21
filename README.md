# Práctica 2: Procesamiento de Datos de Sensores en una Pinza Robótica

Este repositorio contiene los archivos correspondientes al desarrollo de la Práctica 2 de la asignatura, dentro del plan de estudios del Grado en Tecnologías Digitales para la Empresa de la Universidad de Burgos para el curso académico 2025-2026.

El propósito de este proyecto es diseñar, implementar y documentar un sistema de software robusto que aborde un problema real de adquisición de datos en un entorno industrial. La solución desarrollada integra un programa analítico escrito en C++ para el tratamiento y clasificación de señales de sensores acoplados a una pinza robótica, junto con un script de automatización en Bash diseñado para la gestión avanzada de procesos en el sistema operativo.


## Contextualización del Problema Técnico

En entornos automatizados de manufactura y manipulación robótica, la monitorización en tiempo real es crucial para prevenir fallos mecánicos y caídas de material. La pinza robótica objeto de este estudio cuenta con tres elementos clave de diagnóstico de carga: una galga extensométrica para medir la deformación estructural del chasis y dos sensores de fuerza independientes situados en el dedo izquierdo y el dedo derecho respectivamente.

> Durante una sesión experimental de manipulación de objetos, el sistema de almacenamiento sufrió una desincronización en el hilo de escritura de datos, lo que provocó que los registros de las muestras indexadas quedaran desordenados. Como desarrollador, mi tarea ha consistido en construir un binario de alta eficiencia capaz de estructurar la información masiva, validar los rangos, computar las tendencias medias y discernir la estabilidad física de cada maniobra de agarre. Adicionalmente, el despliegue del binario se ha automatizado bajo un script de consola para interactuar de forma transparente con el planificador de tareas del kernel de Unix.


## Desglose y Funcionalidad de los Archivos del Proyecto

El espacio de trabajo se ha compartimentado siguiendo las buenas prácticas de desarrollo de software industrial. Los componentes y la funcionalidad exacta de cada archivo se distribuyen de la siguiente manera:

| Nombre del Archivo | Tipo de Componente | Descripción de su Función Exacta |
| lector_datos.cpp | Código fuente C++ | Contiene los algoritmos analíticos, las estructuras matriciales estáticas de almacenamiento y las directivas de control de flujo para procesar las señales de hardware. |
| ejecutar_analisis.sh | Script de Bash | Actúa como el orquestador del sistema. Automatiza la ejecución del binario en segundo plano, monitoriza sus tiempos y gestiona su finalización forzada si se detectan bloqueos. |
| datos_pinza.txt | Archivo de datos plano | Constituye la fuente de datos primaria extraída del hardware. Almacena las cien muestras desordenadas compuestas por el ID de telemetría y los valores flotantes de los sensores. |
| resultado_pinza.txt | Reporte persistente | Archivo de salida generado automáticamente tras la ejecución. Recoge metadatos del ciclo operativo del kernel, el PID asignado y las tablas resumidas de medias y estabilidad. |
| lector_datos.exe | Binario ejecutable | Archivo compilado resultante de procesar el código fuente. Contiene las instrucciones en código máquina listas para ser instanciadas por el sistema operativo. |

## Requisitos de Compilación y Flujo de Ejecución

Para garantizar la reproducibilidad y verificación de los resultados por parte del tribunal evaluador, el ecosistema se ha diseñado para ser totalmente compatible con la terminal de comandos de Linux o el entorno emulado de Git Bash sobre sistemas operativos Windows.
