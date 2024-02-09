def make_massive():
    mas = []
    mas_izm = int(input("Masīva izmērs: "))
    for i in range(mas_izm):
        mas.append(input(f"Ievadiet massiva [{i}] elementu: "))
    return mas


def find_in_massive(mas:list): # asdasd
    search = int(input("Meklejamais cipars: "))
    for index, i in enumerate(mas):
        print(i, index)
        if i == search:
            print(f"Atradam ciparu {search}, pēc indeksa {index}")
        else:
            print(f"Neatradam masivā ciparu {search}")


find_in_massive(mas = make_massive()) 