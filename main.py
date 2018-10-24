import packages
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

if __name__ == '__main__':
	window = packages.RoomChooser()
	window.show_all()
	Gtk.main()