import pandas as pd
data = {'Name': ['Hritik', 'Harsheet', 'Ravi', 'Akash'] , 'Height': [177, 158, 166, 167],
'Qualification': ['PhD', 'MS', 'MBA', 'BCom.']}
df = pd.DataFrame.from_dict(data)
cols = [21, 14, 60, 30]
df.insert(3, 'Age', cols)
print(df.head())
