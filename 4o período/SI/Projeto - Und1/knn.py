import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split
from sklearn.tree import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# Organizando os dados...
df = pd.read_csv('wifi_localization.txt', header = None, delimiter = "\t")
df.columns=['A1','A2', 'A3', 'A4', 'A5', 'A6', 'A7', 'Saida']
x_train, x_test, y_train, y_test = train_test_split(df.drop('Saida', axis = 1), df['Saida'], test_size=0.30)

# Normalizando...
scaler = StandardScaler()
scaler.fit(x_train)
x_train = scaler.transform(x_train)
x_test = scaler.transform(x_test)

# Treinando...
classifier = KNeighborsClassifier(n_neighbors=1)
classifier.fit(x_train, y_train)

# Realizando previsões...
y_pred = classifier.predict(x_test)

# Mostrando classificações...
score = list()
score.append(accuracy_score(y_test, y_pred))
print(classification_report(y_test, y_pred))
print('\n')
