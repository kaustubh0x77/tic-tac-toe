import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


class Room_Join(Gtk.Dialog):


	def __init__(self, parent, title, label_text):
		Gtk.Dialog.__init__(self, title, parent, 0,
            (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL,
             Gtk.STOCK_OK, Gtk.ResponseType.OK))
		
		self.set_default_size(200, 150)

		self.label = Gtk.Label(label_text)
		self.entry = Gtk.Entry()
		self.entry.set_visibility(False)

		box = self.get_content_area()
		box.add(self.label)
		box.add(self.entry)
		self.show_all()
