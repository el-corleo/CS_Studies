import sys
import whisper


modelName = sys.argv[1]
filename = sys.argv[2]

model = whisper.load_model(modelName)
result = model.transcribe(filename)
print(result["text"])
