@echo off
echo [STEP 1] Compilando e executando o Codigo C...
gcc source.c -o teste_c.exe
teste_c.exe

echo.
echo [STEP 2] Gerando DLL e iniciando Integracao Python...
gcc -shared -o processamento.dll source.c
python main.py

pause
