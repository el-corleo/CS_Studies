import moviepy.editor as mp

clip = mp.VideoFileClip("zoom.mkv")

clip.audio.write_audiofile(r"my_result.mp3")

