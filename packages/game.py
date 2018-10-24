import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


class GameWindow(Gtk.Window) :

	def __init__(self, room_label, user_label) :

		super(Gtk.Window, self).__init__(title = 'Tick-tack-toe')
		self.connect('delete-event', Gtk.main_quit)
		self.set_size_request(width = 600, height = 400)
		header_bar = Gtk.HeaderBar()
		header_bar.set_show_close_button(True)
		header_bar.props.title = 'Tick-tack-toe'
		self.set_titlebar(header_bar)
		self.pane = Gtk.Paned()
		self.add(self.pane)

		self.grid = Gtk.Grid()
		self.grid.set_row_homogeneous(True)
		self.grid.set_column_homogeneous(True)
		self.grid.set_row_spacing(25)
		self.grid.set_column_spacing(25)
		for row in range (0,3) :
			for col in range (0,3) :
				button = Gtk.Button("          ")
				self.grid.attach(child = button,
					left = col, top = row, width = 1, height = 1)

		

		self.box = Gtk.Box(orientation = Gtk.Orientation(1), spacing = 5)
		room_name = Gtk.Label("ROOM : " + room_label)
		userid = Gtk.Label("UserID : " + user_label)
		new_BUTTON = Gtk.Button("New Game")
		new_BUTTON.connect('clicked', self.on_button_click)

		self.box.pack_start(room_name, True, True, 10)
		self.box.pack_start(userid, True, True, 10)
		self.box.pack_start(new_BUTTON, True, True, 10)
		

		self.pane.add1(self.grid)
		self.pane.add2(self.box)


	def on_button_click(self, widget, data = None) :

		pass

if __name__ == '__main__':
	window = GameWindow('', '')
	window.show_all()
	Gtk.main()