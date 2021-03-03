from flask import Flask
from flask import render_template
from flask import request

app = Flask(__name__)

@app.route("/hello", methods=["POST", "GET"])
def index():
	greeting = "Lick my balls"

	if request.method == "POST":
		name = request.form["name"]
		lang = request.form["lang"]
		num = request.form["num"]
		greeting = f"{name} speaks {lang} {num} times a day"
		return render_template("index.html", greeting=greeting)
	
	return render_template("hello_form.html")

if __name__ == "__main__":
	app.run()
