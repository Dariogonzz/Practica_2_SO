#!/bin/bash

# Configuración
EJECUTABLE="./lector_datos.exe"
DATOS="datos_pinza.txt"
INFORME="resultado_pinza.txt"

echo "--- INFORME DE EJECUCIÓN ---" > $INFORME
echo "Fecha: $(date)" >> $INFORME

# 1. VALIDACIÓN: ¿Existen los archivos necesarios?
if [ ! -f "$EJECUTABLE" ]; then
    echo "[ERROR] No se encuentra el archivo $EJECUTABLE." | tee -a $INFORME
    exit 1
fi

if [ ! -f "$DATOS" ]; then
    echo "[ERROR] No se encuentra el archivo de datos $DATOS." | tee -a $INFORME
    exit 1
fi

# 2. LANZAR EJECUCIÓN EN SEGUNDO PLANO (Exigido por la rúbrica)
echo "[BASH] Lanzando $EJECUTABLE en segundo plano..."
$EJECUTABLE >> $INFORME 2>&1 &

# 3. IDENTIFICAR PROCESO
PID=$!
echo "[BASH] PID del proceso: $PID"
echo "PID asociado: $PID" >> $INFORME

# 4. ESPERA CONTROLADA Y VERIFICACIÓN DE FINALIZACIÓN
echo "[BASH] Esperando a que el programa procese los datos..."
sleep 2  # Le damos un margen de tiempo razonable para operar

# 5. FINALIZACIÓN CONTROLADA (Punto crítico de la rúbrica)
if ps -p $PID > /dev/null; then
    echo "[BASH] El proceso $PID sigue activo. Procediendo a finalización controlada..." | tee -a $INFORME
    kill -15 $PID # Intento de cierre limpio (SIGTERM)
    sleep 1
    
    # Si continúa bloqueado, forzar el cierre del proceso
    if ps -p $PID > /dev/null; then
        kill -9 $PID # Cierre forzado (SIGKILL)
    fi
else
    echo "[BASH] El proceso ha finalizado correctamente por sí mismo." | tee -a $INFORME
fi

# 6. LIMPIEZA DE RESIDUOS (Opcional, útil en Windows si usas MSVC)
rm -f *.obj *.ilk *.pdb vc140.pdb

echo "[BASH] Análisis completado con éxito."