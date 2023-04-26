import Tkinter as tk
import os
import tkFileDialog as filedialog
from argparse import Namespace

from PIL import ImageTk, Image

from module.modules.utilities import VALID_CATEGORY

class Gui:
    def __init__(self):
        self.arguments = Namespace()
        self.__set_init_arguments()

    def __set_init_arguments(self):
        self.arguments.books = 1000
        self.arguments.filter = None
        self.arguments.genres = None
        self.arguments.keyword = None
        self.arguments.sorting = None
        self.arguments.title = None
        self.arguments.json = None

    def get_arguments(self):
        return self.arguments

    def start_gui(self):

        def select_directory():

            filetypes = [('JSON files', '*.json')]

            filepath = filedialog.askopenfilename(filetypes=filetypes)
            print("JSON files in the directory:", filepath)

        def toggle_radiobuttons(*args):
            if var3.get():
                radio1.config(state="normal")
                radio2.config(state="normal")

            else:
                radio1.config(state="disabled")
                radio2.config(state="disabled")

        def toggle_entry_books_amount(*args):
            if var.get():
                entry_books_amount.config(state="normal")
            else:
                entry_books_amount.config(state="disabled")

        def toggle_entry_genres(*args):
            if var1.get():
                entry_genre.config(state="normal")
            else:
                entry_genre.config(state="disabled")

        def toggle_entry_title(*args):
            if var2.get():
                entry_title.config(state="normal")
            else:
                entry_title.config(state="disabled")

        def toggle_entry_keywords(*args):
            if var4.get():
                keyword_entry.config(state="normal")
            else:
                keyword_entry.config(state="disabled")

        def toggle_select_dir(*args):
            if var_select.get():
                btn_select_dir.config(state="normal")
            else:
                btn_select_dir.config(state="disabled")

        def save_input():
            books = entry_books_amount.get()
            if books:
                self.arguments.books = int(books)
            genre_list = []
            genres = entry_genre.get().split()
            if genres:
                for genre in genres:
                    if genre.lower() in VALID_CATEGORY:
                        genre_list.append(genre.lower())
                self.arguments.genres = genre_list
            title = entry_title.get().split()
            if title:
                self.arguments.title = title
            if radio_var.get() == 1:
                self.arguments.sorting = ["price", "ascending"]
            if radio_var.get() == 2:
                self.arguments.sorting = ["price", "descending"]
            keyword = keyword_entry.get().split()
            if keyword:
                self.arguments.keyword = keyword

            root.destroy()

        root = tk.Tk()
        root.title("Web Scraper")

        root.minsize(1000, 500)
        root.maxsize(1000, 500)
        # var for entry_books_amount point (how many books to scrape)
        var = tk.IntVar()
        var1 = tk.IntVar()
        var2 = tk.IntVar()
        var3 = tk.IntVar()
        var4 = tk.IntVar()



        # Create a button to close the window
        # close_button = tk.Button(root, text="Close Window", command=close_window)
        # close_button.pack()
        # canvas1 = tk.Canvas(root, width=400, height=350)
        # self_bg = ImageTk.PhotoImage(Image.open('bookies.jpg'))
        # canvas1.create_image(0, 0, anchor="nw", image=self_bg, tags="bg")
        # # display the canvas
        # canvas1.pack(fill="both", expand=True)
        #
        # # make the background image resize with the window
        # canvas1.tag_lower("bg", "all")


        # check button for amount of books
        ch_B_amount_of_books = tk.Checkbutton(root, text="how many books to scrape:", variable=var,
                                              command=toggle_entry_books_amount)
        # entry_books_amount is disabled untill check button is clicked that u want to have input in books
        entry_books_amount = tk.Entry(root, state="disabled")

        # for genres
        ch_B_genres = tk.Checkbutton(root, text="Which Genres:", variable=var1, command=toggle_entry_genres)
        entry_genre = tk.Entry(root, state="disabled")

        # for titles
        ch_B_title = tk.Checkbutton(root, text="Input Title to search for:", variable=var2, command=toggle_entry_title)
        entry_title = tk.Entry(root, state="disabled")

        # for radio buttons
        ch_B_sorting = tk.Checkbutton(root, text="Do You want sorting", variable=var3, command=toggle_radiobuttons)

        radio_var = tk.IntVar()
        radio1 = tk.Radiobutton(root, text="Ascending", variable=radio_var, value=1, state="disabled")
        radio2 = tk.Radiobutton(root, text="Descending", variable=radio_var, value=2, state="disabled")

        # for keywords
        ch_B_keywords = tk.Checkbutton(root, text="Do You want searching by keywords?", variable=var4,
                                       command=toggle_entry_keywords)

        keyword_entry = tk.Entry(root, text="Keyword:", state="disabled")

        # for JSON input
        var_select = tk.IntVar()
        ch_B_JSON = tk.Checkbutton(root, text="Select a directory", command=toggle_select_dir, variable=var_select)

        btn_select_dir = tk.Button(root, text="Select directory", command=select_directory, state="disabled")

        """ command=(here we need function which gets all inputs like argparser)"""
        scrape_button = tk.Button(root, text="Scrape", command=save_input)
        # like -b Arg for arg parser
        ch_B_amount_of_books.place(x=0, y=0)
        entry_books_amount.place(x=200, y=0)

        # like -g for argparser .
        ch_B_genres.place(x=0, y=100)
        entry_genre.place(x=200, y=100)

        # like -t
        ch_B_title.place(x=0, y=200)
        entry_title.place(x=200, y=200)

        # like -s
        ch_B_sorting.place(x=800, y=00)
        radio1.place(x=840, y=25)
        radio2.place(x=840, y=50)

        ch_B_keywords.place(x=700, y=100)
        keyword_entry.place(x=800, y=130)

        # json_entry.pack()
        ch_B_JSON.place(x=400, y=300)
        btn_select_dir.place(x=550, y=300)

        scrape_button.place(x=500, y=450)

        # this label is just for testing purposes remove later functions just as print
        label_test = tk.Label(root, text="")
        label_test.pack()

        root.mainloop()


