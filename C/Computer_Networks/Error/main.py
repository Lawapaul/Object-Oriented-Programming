def checksum(data:bytes)->int:
    checksum=0;
    for i in range(0,len(data),2):
        word=data[i] + (data[i+1]<<8) if i+1<len(bytes) else data[i]
        checksum+=word
        checksum=(checksum & 0xFFFF) + (checksum >> 16)
    checksum=~checksum & 0xFFFF
    
def check_checksum(data:bytes,received_checksum: int)->bool:
    result=checksum(data)
    if(result==received_checksum):
        return True
    return False

def lrc(data:bytes)->int:
    lrc=0;
    for byte in data:
        lrc^=byte
    return lrc

def check_lrc(data:bytes,received_lrc:int)->bool:
    result=lrc(data)
    if(result==received_lrc):
        return True
    return False

def vrc(data:bytes)->str:
    vrc=""
    for byte in data:
        parity=bin(byte).count('1')%2
        vrc+=str(parity)
    return vrc

def check_vrc(data:bytes,received_vrc: str)->bool:
    result=vrc(data)
    if(received_vrc==result):
        return True
    return False

def xor(a,b):
    result=[]
    for i in range(0,len(b)):
        if(a[i]==b[i]):
            result.append('1')
        else:
            result.append('0')
    return "".join(result)

def mod2div(divided,divisor):
    pick=len(divisor)
    tmp=divided[0:pick]
    while pick<len(divided):
        if(tmp[0]=='1'):
            xor(divided,tmp) + divided[pick]
        else:
            xor('0'*pick,tmp) + divided[pick]
        pick+=1
        
    if tmp[0]=='1':
        xor(divisor,tmp)
    else:
        xor('0'*pick,tmp)

def encoded(data,key):
    appended_data=data + '0'*(len(key-1))
    remainder=mod2div(appended_data,key)
    codeword=data+remainder
    return codeword

def calculate_parity_bits(data):
    n = len(data)
    r = 0
    while (2 ** r) < (n + r + 1):
        r += 1
    return r

def position_parity_bits(data, r):
    j = 0
    k = 0
    m = len(data)
    n = m + r
    result = ''
    for i in range(1, n + 1):
        if i == (2 ** j):
            result += '0'
            j += 1
        else:
            result += data[k]
            k += 1
    return result

def calculate_parity_values(arr, r):
    n = len(arr)
    for i in range(r):
        x = (2 ** i)
        parity = 0
        for j in range(1, n + 1):
            if j & x == x:
                parity ^= int(arr[j - 1])
        arr = arr[:x-1] + str(parity) + arr[x:]
    return arr

def detect_and_correct(arr, r):
    n = len(arr)
    error_pos = 0
    for i in range(r):
        x = (2 ** i)
        parity = 0
        for j in range(1, n + 1):
            if j & x == x:
                parity ^= int(arr[j - 1])
        error_pos += x if parity != 0 else 0
    if error_pos != 0:
        arr = list(arr)
        arr[error_pos - 1] = '0' if arr[error_pos - 1] == '1' else '1'
        arr = ''.join(arr)
    return arr

def hamming_code(data):
    r = calculate_parity_bits(data)
    arr = position_parity_bits(data, r)
    arr = calculate_parity_values(arr, r)
    return arr

def main():
    data = input("Enter binary data: ")
    encoded_data = hamming_code(data)
    print(f"Encoded data with parity bits: {encoded_data}")
    introduce_error = input("Do you want to introduce an error? (yes/no): ").lower()
    if introduce_error == 'yes':
        error_bit = int(input("Enter the bit position to flip (1-indexed): ")) - 1
        encoded_data = list(encoded_data)
        encoded_data[error_bit] = '0' if encoded_data[error_bit] == '1' else '1'
        encoded_data = ''.join(encoded_data)
        print(f"Encoded data with an error introduced: {encoded_data}")
        corrected_data = detect_and_correct(encoded_data, calculate_parity_bits(data))
        print(f"Corrected data: {corrected_data}")
    else:
        print(f"No error introduced. Encoded data remains: {encoded_data}")

if __name__ == "__main__":
    main()
