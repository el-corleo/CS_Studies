import pandas as pd
from sklearn.model_selection import train_test_split
#Random Forests take multiple decision trees and average them to produce a more accurate predictor
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error

#Steps to building a model [ref. https://www.kaggle.com/dansbecker/your-first-machine-learning-model]
#Define: What type of model will it be? A decision tree? Some other type of model? Some other parameters of the model type are specified too.
#Fit: Capture patterns from provided data. This is the heart of modeling.
#Predict: Just what it sounds like
#Evaluate: Determine how accurate the model's predictions are.
def get_mae(mln, train_X, val_X, train_y, val_y):
	#Define model as decision tree
	housing_model = RandomForestRegressor(max_leaf_nodes=mln, random_state=0)
	#Fit model
	housing_model.fit(train_X, train_y)
	#Predict
	predicted_home_prices = housing_model.predict(val_X)
	#Validate model
	mae = mean_absolute_error(val_y, predicted_home_prices)
	return(mae)


data_file_path = 'melb_data.csv'
housing_data = pd.read_csv(data_file_path)

#drops data points with missing fields
housing_data.dropna(axis=0)

#y is the standard variable for prediction target
y = housing_data.Price
#X is the standard variable for the feature set
#housing_data.columns will display all columns in the data set
housing_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']
X = housing_data[housing_features]

#Split into validation and training data
train_X, val_X, train_y, val_y = train_test_split(X, y, random_state=0)

#Compare models with different num leaves
for max_leaf_nodes in [5,50,500,5000]:
	mae = get_mae(max_leaf_nodes, train_X, val_X, train_y, val_y)
	print("Max Leaf Nodes: %d \t\t Mean Absolute Error: %d" %(max_leaf_nodes, mae))