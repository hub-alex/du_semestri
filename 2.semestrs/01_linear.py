def make_massive()->list:
    mas = []
    mas_izm = int(input("Masīva izmērs: "))
    for i in range(mas_izm):
        cipars = int(input(f"Ievadiet massiva [{i}] elementu: "))
        mas.append(cipars)
    return mas


def find_in_massive(mas:list):
    """Meklejam ciparu masivā"""     
    
    search = int(input("Meklejamais cipars: "))
    
    for index, i in enumerate(mas):
        # print(i, search)
        if i == search:
            print(f"Atradam ciparu {search}, pēc indeksa {index}")
            return
    
    print(f"Neatradam masivā ciparu {search}")


if __name__ == "__main__":
    massive = make_massive()
    find_in_massive(massive)