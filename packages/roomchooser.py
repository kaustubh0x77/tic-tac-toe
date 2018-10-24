import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk
from .dialog_box import Room_Join

class RoomChooser(Gtk.Window) : 

	def __init__ (self):
		super(Gtk.Window, self).__init__(title = 'Tick-Tack-Toe')
		self.connect('delete-event', Gtk.main_quit)
		self.box = Gtk.Box(orientation = Gtk.Orientation(1), spacing = 5)
		self.add(self.box)
		self.set_size_request(width = 300, height = 200)
		self.set_resizable(False)

		join_BUTTON = Gtk.Button('Join a Room')
		host_BUTTON = Gtk.Button('Host a Room')
		random_BUTTON = Gtk.Button('Join a random game')

		join_BUTTON.connect('clicked', self.on_click_join)
		host_BUTTON.connect('clicked', self.on_click_host)
		random_BUTTON.connect('clicked', self.on_click_random)


		self.entry_box = Gtk.Box()
		user_LABEL = Gtk.Label(label = 'UserID :')
		user_ENTRY = Gtk.Entry()
		user_ENTRY.set_editable(True)


		self.entry_box.pack_start(user_LABEL, True, True, 10)
		self.entry_box.pack_start(user_ENTRY, True, True, 10)
		
		self.box.pack_start(self.entry_box, True, True, 0)
		self.box.pack_start(join_BUTTON, True, True, 0)
		self.box.pack_start(host_BUTTON, True, True, 0)
		self.box.pack_start(random_BUTTON, True, True, 0)


	def on_click_join(self, widget, data = None):
		dialog = Room_Join(self, 'Join a Room', 'Enter code : ')
		response = dialog.run()
		if response == Gtk.ResponseType.OK : 
			pass_code = dialog.entry.get_text()
		elif response == Gtk.ResponseType.CANCEL : 
			pass

		dialog.destroy()


		self.move_to_next_page()


	def on_click_host(self, widget, data = None):
		dialog = Room_Join(self, 'Host your Room', 'Create a code : ')
		response = dialog.run()
		if response == Gtk.ResponseType.OK : 
			pass_code = dialog.entry.get_text()
		elif response == Gtk.ResponseType.CANCEL : 
			pass

		dialog.destroy()

		self.move_to_next_page()



	def on_click_random(self, widget, data = None):
		pass


	def move_to_next_page(self):
		pass



if __name__ == '__main__' :
	window = RoomChooser()
	window.show_all()
	Gtk.main()


