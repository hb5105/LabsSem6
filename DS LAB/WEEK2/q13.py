import pandas as pd
data = {'Name': ['Hritik', 'Harsheet', 'Ravi', 'Akash'] , 'Height': [177, 158, 166, 167],
'Qualification': ['PhD', 'MS', 'MBA', 'BCom.']}
df = pd.DataFrame.from_dict(data)
addr_list = ['Mumbai', 'Delhi', 'Chennai', 'Pune']
df['Address'] = addr_list
print(df.head())
