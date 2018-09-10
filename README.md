# Emotiondetection

## Dependencies
    openCV version 3 or higher.
    Tensorflow.

# Steps to get it to work
## Step 1: There already exists a file called retrained_graphs.pb and a retrained_labels.txt. Either run it as is or delete them both and run the code for retrain.py which will regenerate those two. The input goes in the folder faces. Create new folders for new emotions you would want to add. Currently there are only 2 and all the data is from Google. You could also add your own faces emotions to train it better.
    retrain.py has very good documentation (because its not my code :p)
    To run it type the following command on your terminal: python retrain.py --output_graph=retrained_graph.pb --output_labels=retrained_labels.txt --architecture=MobileNet_1.0_224 --image_dir=faces

## Step 2: The code capture is just for video capture which then passes it to classifier which returns the classification. After generating the labels and graphs just run: python capture.py.

## Notes: In capture.py make sure to edit the path for the face detection xml. There are two in my repositories for frontal face, the others can be found in your openCV directory, follow the same path format as in the code. And make sure to use "\\\\".
