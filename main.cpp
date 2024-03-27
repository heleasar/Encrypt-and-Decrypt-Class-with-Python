class Crypto:
    def __init__(self, plaintext_filename: str, ciphertext_filename: str, key: int):
        self.plaintext_filename = plaintext_filename
        self.ciphertext_filename = ciphertext_filename
        self.key = key
        self.Encrypt()
        
    def Encrypt(self):
        with open(self.plaintext_filename, 'r') as plain_file:
            with open(self.ciphertext_filename, 'w') as cipher_file:
                for ch in plain_file.read():
                    num = ord(ch)
                    num += self.key
                    cipher_file.write(str(num) + ' ')
                    
    def Decryption(self, c_file: str, p_file: str, k: int):
        with open(c_file, 'r') as cipher_file:
            with open(p_file, 'w') as plain_file:
                numbers = cipher_file.read().split()
                for num in numbers:
                    char = chr(int(num) - k)
                    plain_file.write(char)

