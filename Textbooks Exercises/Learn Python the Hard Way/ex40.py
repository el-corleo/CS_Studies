import ex40_module as mod


class WhyMe:

    def __init__(self):
        self.answer = "Because you're an idiot!"
        
    def why_me(self):
        print(self.answer)


mod.print_thing("thing")

wm = WhyMe()

wm.why_me()
