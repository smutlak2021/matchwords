import plotly.graph_objects as go
import pandas as pd

# 1. Read the data from the CSV file
try:
    df = pd.read_csv("result.csv")  # Replace "your_data.csv" with the actual filename
    x = df['x']  # Replace 'x' with the actual column name for the x-coordinates
    y = df['y']  # Replace 'y' with the actual column name for the y-coordinates
    z = df['z']  # Replace 'z' with the actual column name for the z-coordinates
except FileNotFoundError:
    print("Error: CSV file not found. Please make sure the file exists and the path is correct.")
    exit()  # Exit the script if the file is not found
except KeyError as e:
    print(f"Error: Column '{e}' not found in the CSV file. Please check the column names.")
    exit()


print (len(x))
colors = ['blue'] * len(x)
print (len(colors))
colors[:100] = ['green'] * 100
print (len(colors))
# colors[229] = 'red'
# colors[483] = 'red'
# print (len(colors))


fig = go.Figure(data=[go.Scatter3d(x=x, y=y, z=z, mode='markers', marker=dict(color=colors))])
fig.update_layout(
    title="3D Scatter Plot",  # Add a title
    scene=dict(  
        xaxis_title="X-axis",
        yaxis_title="Y-axis",
        zaxis_title="Z-axis",
    ),
    margin=dict(l=0, r=0, b=0, t=50) 
)


fig.show()