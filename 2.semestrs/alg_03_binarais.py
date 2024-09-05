def binarais(mas, x):
    left = 0
    right = len(mas)-1

    while left <= right:
        mid = (left + right) // 2
        if mas[mid] < x:
            left = mid + 1
        elif mas[mid] > x:
            right = mid-1
        else:
            return "Atrada!"
        print(f"{mas[mid] = }, {x = }")

    return "Neatrada!"

x = int(input("Ievadiet meklējamo ciparu: "))
mas = int(input("Ievadiet masīva garumu: "))
mas = range(mas)

print(binarais(mas=mas, x=x))