import ipaddress

def dec_bin(ip):
    return "".join([format(int(x), '08b') for x in ip.split('.')])

def hex_bin(ip):
    return "".join([format(int(x), '02X') for x in ip.split('.')])

def bin_dec(ip):
    return ".".join(str(int(x, 2)) for x in ip.split('.'))

def hex_dec(ip):
    return ".".join(str(int(x, 16)) for x in ip.split('.'))

def identify_class(ip):
    first_octet = int(ip.split('.')[0])
    if first_octet < 128:
        return 'A'
    elif first_octet < 192:
        return 'B'
    elif first_octet < 224:
        return 'C'
    elif first_octet < 240:
        return 'D'
    else:
        return 'E'

def calculate_subnet_details(ip, no_of_subnets):
    ip_network = ipaddress.IPv4Network(ip, strict=False)
    subnets = list(ip_network.subnets(new_prefix=ip_network.prefixlen + (no_of_subnets.bit_length() - 1)))
    result = []
    for subnet in subnets:
        network_id = subnet.network_address
        broadcast_address = subnet.broadcast_address
        first_address = subnet.network_address + 1
        last_address = subnet.broadcast_address - 1
        available_hosts = subnet.num_addresses - 2
        result.append({
            "Subnet": str(subnet),
            "Network ID": str(network_id),
            "Broadcast Address": str(broadcast_address),
            "First Address": str(first_address),
            "Last Address": str(last_address),
            "Available Hosts": available_hosts
        })
    return result

def main():
    print("1. Conversion\n2. Perform subnetting and Classification\n")
    choice = int(input("Enter Input: "))
    if choice == 1:
        ip = input("Enter the IP Address: ")
        ip_format = input("Enter the current format (binary/decimal/hexadecimal): ")
        convert_to = input("Enter the format to convert to (binary/decimal/hexadecimal): ")

        if ip_format == 'binary' and convert_to == 'decimal':
            result = bin_dec(ip)
        elif ip_format == 'decimal' and convert_to == 'binary':
            result = dec_bin(ip)
        elif ip_format == 'decimal' and convert_to == 'hexadecimal':
            result = hex_bin(ip)
        elif ip_format == 'hexadecimal' and convert_to == 'decimal':
            result = hex_dec(ip)
        else:
            result = "Invalid Conversion"

        print(f"Converted IP Address: {result}")

    elif choice == 2:
        ip = input("Enter the IP Address (in dotted decimal format): ")
        num_subnets = int(input("Enter the number of subnets: "))
        ip_class = identify_class(ip)
        print(f"Class of IP Address: {ip_class}")
        subnet_details = calculate_subnet_details(ip + "/24", num_subnets)  # Assuming /24 for simplicity
        for subnet in subnet_details:
            print(f"Subnet: {subnet['Subnet']}")
            print(f" Network ID: {subnet['Network ID']}")
            print(f" Broadcast Address: {subnet['Broadcast Address']}")
            print(f" First Address: {subnet['First Address']}")
            print(f" Last Address: {subnet['Last Address']}")
            print(f" Available Hosts: {subnet['Available Hosts']}\n")

    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()
