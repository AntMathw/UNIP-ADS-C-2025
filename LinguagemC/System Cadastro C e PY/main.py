import ctypes
import os
import time
import pwinput

# 1. Configuração do caminho da DLL
caminho_atual = os.getcwd()
dll_path = os.path.join(caminho_atual, "processamento.dll")

try:
    # 2. Carrega a DLL
    lib = ctypes.CDLL(dll_path)

    # 3. Mapeamento das funções da DLL (Ajustado para os nomes do C)
    lib.validar_cadastro.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
    lib.validar_cadastro.restype = ctypes.c_int
    
    # Verifique se no seu C está 'avaliar_senha' ou 'validar_senha'
    # Usei 'avaliar_senha' que foi o que passamos nos passos anteriores
    lib.avaliar_senha.argtypes = [ctypes.c_char_p]
    lib.avaliar_senha.restype = ctypes.c_int

    def salvar_no_arquivo(nome, cpf, email):
        """Função para persistência de dados em TXT"""
        try:
            with open("cadastros.txt", "a", encoding="utf-8") as arquivo:
                arquivo.write(f"Nome: {nome} | CPF: {cpf} | Email: {email}\n")
            print(f"\n[DISCO] Cadastro de {nome} salvo com sucesso em 'cadastros.txt'!")
        except Exception as e:
            print(f"Erro ao salvar arquivo: {e}")

    def executar_sistema():
        print("=== SISTEMA HIBRIDO: PYTHON + C ===")
        
        nome = input("Digite seu nome: ").title()
        
        # Loop para CPF e Email
        while True:
            cpf = input("Digite o CPF (apenas 11 numeros): ")
            email = input("Digite o Email: ")

            print("\n[C] Validando dados básicos...")
            resultado = lib.validar_cadastro(cpf.encode('utf-8'), email.encode('utf-8'))

            if resultado == 0:
                print("✅ CPF e Email aprovados!")
                break
            elif resultado == 1:
                print("❌ ERRO NO C: CPF invalido.")
            elif resultado == 2:
                print("❌ ERRO NO C: Email invalido.")

        # Loop para Senha
        print('\n--- SEGURANÇA DA SENHA ---')
        while True:
            senha = pwinput.pwinput(prompt="Crie uma senha: ", mask="*")
            
            # Chamando a função da DLL
            nota = lib.avaliar_senha(senha.encode('utf-8'))

            if nota == 1:
                print('🔴 Senha FRACA! (Mínimo 6 caracteres)')
            elif nota == 2:
                print('🟡 Senha MEDIA! (Misture letras e números)')
            elif nota == 3:
                print('🟢 Senha FORTE!')
                break
        
        # FINALIZAÇÃO: Salva os dados após todas as validações passarem
        salvar_no_arquivo(nome, cpf, email)
        print("\n=== PROCESSO FINALIZADO ===")

except Exception as e:
    print(f"ERRO DE CONFIGURAÇÃO: {e}")
    exit()

if __name__ == "__main__":
    executar_sistema()
