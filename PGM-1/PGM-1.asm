    LIST P=16F886         ; Define el microcontrolador específico, en este caso, el PIC16F886.
    INCLUDE <P16F886.INC> ; Incluye el archivo de cabecera con los registros y definiciones específicos del PIC16F886.
    __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF & _LVP_OFF
                          ; Configuración del PIC:
                          ; _FOSC_INTOSCIO: Configura el oscilador interno.
                          ; _WDTE_OFF: Deshabilita el Watchdog Timer.
                          ; _PWRTE_ON: Habilita el temporizador de encendido (Power-up Timer).
                          ; _MCLRE_OFF: Deshabilita la función MCLR (para usar el pin como entrada general).
                          ; _LVP_OFF: Deshabilita la programación de bajo voltaje (Low Voltage Programming).

; Definiciones
#define LED_PIN PORTB,5   ; Define el pin RB5 (el pin físico 13 en Arduino) como LED_PIN.

    ORG 0x00              ; Establece la dirección de origen del programa en 0x00 (inicio del programa).
    GOTO INICIO           ; Salta a la etiqueta INICIO, donde comienza la configuración.

; Configuración inicial
INICIO:
    BSF STATUS, RP0       ; Cambia al banco de registros 1 (necesario para acceder a TRISB).
    BCF STATUS, RP1       ; Asegura que esté en el banco 1 (RP1=0 y RP0=1 configuran el banco 1).

    CLRF TRISB            ; Configura todos los pines de PORTB como salidas (TRISB = 0).
    BCF STATUS, RP0       ; Regresa al banco 0 para operaciones con los puertos de E/S (entradas/salidas).

BUCLE:
    BSF LED_PIN           ; Enciende el LED (pone el pin RB5 en HIGH).
    CALL DELAY_1S         ; Llama a la subrutina de retardo de 1 segundo.

    BCF LED_PIN           ; Apaga el LED (pone el pin RB5 en LOW).
    CALL DELAY_1S         ; Llama nuevamente a la subrutina de retardo de 1 segundo.

    GOTO BUCLE            ; Vuelve a repetir el bucle (parpadeo continuo del LED).

; Rutina de retardo de 1 segundo (aproximada para un reloj de 4MHz)
DELAY_1S:
    MOVLW D'250'          ; Carga el literal 250 en el registro W (4ms * 250 = 1 segundo).
    MOVWF CONTADOR1       ; Mueve el valor 250 al registro CONTADOR1 (ciclos exteriores de 4ms).

DELAY_INNER:
    MOVLW D'250'          ; Carga nuevamente el valor 250 en W para el contador interior.
    MOVWF CONTADOR2       ; Mueve el valor 250 al registro CONTADOR2 (ciclos interiores de 4ms).

DELAY_LOOP:
    NOP                   ; No Operation (espera).
    NOP
    NOP                   ; Tres NOPs para agregar un pequeño retardo.
    DECFSZ CONTADOR2, F   ; Decrementa CONTADOR2 y salta si llega a 0.
    GOTO DELAY_LOOP       ; Repite el bucle interno hasta que CONTADOR2 sea 0.

    DECFSZ CONTADOR1, F   ; Decrementa CONTADOR1 y salta si llega a 0.
    GOTO DELAY_INNER      ; Repite el bucle exterior hasta que CONTADOR1 sea 0.

    RETURN                ; Regresa al programa principal después del retardo.

    END                   ; Final del programa.
