import moviepy.editor as mp

filename = input("Enter filename: (must be in same directory; must have extension) ")

clip = mp.VideoFileClip(filename)
clip.audio.write_audiofile(f"{filename[:filename.find('.')]}.mp3")

