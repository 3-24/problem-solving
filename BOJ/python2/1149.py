def main():
    N = int(raw_input())
    RGB=[[0,0,0]]
    for i in range (N):
        IN=map(int,raw_input().split())
        RGB.append(IN)
    price = [[0,0,0]]
    for i in range (1,N+1):
        price_red = price[i-1][0]
        price_green = price[i-1][1]
        price_blue = price[i-1][2]
        added_red = RGB[i][0]
        added_green = RGB[i][1]
        added_blue = RGB[i][2]
        added_list = [min(price_green + added_red, price_blue + added_red),
                      min(price_red + added_green, price_blue + added_green),
                      min(price_red + added_blue, price_green + added_blue)]
        price.append(added_list)
    minN = min(price[N][0],price[N][1],price[N][2])
    return minN


print main()