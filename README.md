# OpenSCAD
This is where I keep the patches to OpenSCAD

## Feature request 1.
I have scad file that builds a finger or thumb splint and has a lot of model parameters to tweak it into your personal finger/thumb shape, see https://www.thingiverse.com/thing:7145288 . The many parameters are divided into tabs. When a scad file is loaded all tabs are expanded on the initial preview and that scares off any user of the scad file when they see the many parameters. Opening all tabs collapsed removes the scarry part and gives a more easier access to the parameters. Its much more easier if you can collapse all tabs anf then just expand the tab where you want to change a parameter.
For me a user is somebody who uses the customizer and doesnot want to see or alter the scad code.
I noticed that this is not the first time a collapse/expand tabs request is made. To see the suggested change in action see the youtube video with a Windows version: https://www.youtube.com/watch?v=t_vN4xlLtOo .

Suggested change:
- after loading the scad file all tabs are collapsed or expanded selected via a preference option.
- add a "Collapse all tabs" and "Expand all tabs" entry to the combobox "Show Details" of the customizer.
- maintain the current behavior of expanding and collapsing tabs in the customizer.
- any newly added tab to the scad file is expanded when previewed.

The changed locale language files and changed code files are available in this repository.

Alternatives:
- Keeping the current unfriendly behavior. Not really...
- Providing users with a version of OpenSCAD (Windows and Linux) which includes the suggested change.

Screenshots:

<img width="871" height="557" alt="Image" src="Pictures/preferences_curtomizer.png" />

<img width="871" height="557" alt="Image" src="Pictures/combobox_details.png" />

