import pandas as pd
import requests
from bs4 import BeautifulSoup
url = "https://docs.google.com/document/d/e/2PACX-1vTER-wL5E8YC9pxDx43gk8eIds59GtUUk4nJo_ZWagbnrH0NFvMXIw6VWFLpf5tWTZIT9P9oLIoFJ6A/pub"
def decode(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')
    data = []
    for row in table.find_all('tr'):
        cols = row.find_all('td')
        data.append([col.text.strip() for col in cols])
    df = pd.DataFrame(data[1:],columns=data[0])
    df['x-coordinate'] = df['x-coordinate'].astype(int)
    df['y-coordinate'] = df['y-coordinate'].astype(int)
    b = df['x-coordinate'].max()
    a = df['y-coordinate'].max()
    coord_dict = {}
    for i in range(len(df)):
        character = df.loc[i, 'Character']
        if character not in coord_dict:
            coord_dict[character] = []
        x = int(df.loc[i, 'x-coordinate'])
        y = int(df.loc[i, 'y-coordinate'])
        coord_dict[character].append((x, y))

    grid = [[' ' for i in range(b + 1)] for j in range(a + 1)]
    for char, coords in coord_dict.items():
        for x, y in coords:
            grid[y][x] = char

    for row in grid:
        print(''.join(str(cell) for cell in row))

decode(url)





