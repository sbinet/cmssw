package confdb.gui;

import javax.swing.*;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.*;

import confdb.data.*;

import confdb.gui.treetable.*;


/**
 * ParameterTableMouseListener
 * ---------------------------
 * @author Philipp Schieferdecker
 *
 */
public class ParameterTableMouseListener extends MouseAdapter
                                         implements ActionListener
{
    //
    // member data
    //

    /** frame, to position dialogs */    
    private JFrame frame = null;

    /** the corresponding TreeTable */
    private TreeTable treeTable = null;

    /** the corresponding TreeTableTableModel */
    private TreeTableTableModel tableModel = null;
    
    /** the corresponding TreeTableTreeModel */
    private ParameterTreeModel treeModel = null;
    
    /** current parameter (set by MouseAdapter for ActionListener) */
    private Parameter parameter = null;
    

    /**Temporary solution to fix display problems for untracked parameter removal*/
    ConfDbGUI confDbGUI;

    //
    // construction
    //

    public ParameterTableMouseListener(JFrame frame,TreeTable treeTable)
    {
	this.frame      = frame;
	this.treeTable  = treeTable;
	this.treeModel  = (ParameterTreeModel)treeTable.getTree().getModel();
	this.tableModel = (TreeTableTableModel)treeTable.getModel();
    }


    public ParameterTableMouseListener(JFrame frame,TreeTable treeTable,ConfDbGUI confDbGUI)
    {
	this(frame,treeTable);
	this.confDbGUI = confDbGUI;
    }


    //
    // member functions
    //

    /** MouseAdapter: mousePressed() */
    public void mousePressed(MouseEvent e)  { maybeShowPopup(e); }
    
    /** MouseAdapter: mousePressed() */
    public void mouseReleased(MouseEvent e) { maybeShowPopup(e); }
    
    /** popup triggered */
    private void maybeShowPopup(MouseEvent e)
    {
	if (!e.isPopupTrigger()) return;

	Point     pnt = e.getPoint();
	int       col = treeTable.columnAtPoint(pnt);
	int       row = treeTable.rowAtPoint(pnt);
	
	parameter = (Parameter)tableModel.nodeForRow(row);
	
	if (col!=0) return;
	    
	JPopupMenu popup  = new JPopupMenu();	    
	Object     parent = parameter.parent();
	Boolean    bRemoveParam = false;
	

	if(parent instanceof Instance){
	    Template template =  ((Instance)parent).template();
	    Parameter pExists = template.parameter(parameter.name());
	    if(pExists==null){
		bRemoveParam = true;
	    }
	}
	    
	if (parameter instanceof VPSetParameter) {
	    JMenuItem  menuItem = new JMenuItem("Add PSet");
	    menuItem.addActionListener(this);
	    popup.add(menuItem);
	    if (parent instanceof PSetParameter || bRemoveParam) {
		popup.addSeparator();
		menuItem = new JMenuItem("Remove Parameter");
		menuItem.addActionListener(this);
		popup.add(menuItem);
	    }
	    popup.show(e.getComponent(),e.getX(),e.getY());
	}
	else if (parameter instanceof PSetParameter) {
	    JMenuItem  menuItem = new JMenuItem("Add Parameter");
	    menuItem.addActionListener(this);
	    popup.add(menuItem);
	    if (parent instanceof VPSetParameter||
		parent instanceof PSetParameter || bRemoveParam) {
		popup.addSeparator();
		menuItem = new JMenuItem("Remove Parameter");
		menuItem.addActionListener(this);
		popup.add(menuItem);
	    }
	    popup.show(e.getComponent(),e.getX(),e.getY());
	}
	else if (parent instanceof PSetParameter || bRemoveParam) {
	    JMenuItem  menuItem = new JMenuItem("Remove Parameter");
	    menuItem.addActionListener(this);
	    popup.add(menuItem);
	    popup.show(e.getComponent(),e.getX(),e.getY());
	}


    }
	
    /** ActionListener: actionPerformed() */
    public void actionPerformed(ActionEvent e)
    {
	JMenuItem src = (JMenuItem)e.getSource();
	String    cmd = src.getText();
	Object parent = parameter.parent();
	    
	// vpset
	if (parameter instanceof VPSetParameter) {
	    if (cmd.equals("Add PSet")) {
		VPSetParameter vpset = (VPSetParameter)parameter;
		addParameterSet(vpset);
	    }
	    else if (parent instanceof PSetParameter) {
		PSetParameter pset = (PSetParameter)parent;
		if (cmd.equals("Remove Parameter")) {
		    int index = pset.removeParameter(parameter);
		    treeModel.nodeRemoved(pset,index,parameter);
		    notifyParent(pset);
		}
	    }
	    else if (parent instanceof Instance) {
		Instance instance = (Instance)parent;
		if (cmd.equals("Remove Parameter")) {
		    instance.removeUntrackedParameter(parameter);
		    confDbGUI.refreshParameters();
		}
	    }
	}
	// pset
	else if (parameter instanceof PSetParameter) {
	    if (cmd.equals("Add Parameter")) {
		PSetParameter pset = (PSetParameter)parameter;
		addParameter(pset);
	    }
	    else if (parent instanceof VPSetParameter) {
		VPSetParameter vpset = (VPSetParameter)parent;
		PSetParameter  pset  = (PSetParameter)parameter;
		if (cmd.equals("Remove Parameter")) {
		    int index = vpset.removeParameterSet(pset);
		    treeModel.nodeRemoved(vpset,index,pset);
		    notifyParent(vpset);
		}
	    }
	    else if (parent instanceof PSetParameter) {
		PSetParameter pset = (PSetParameter)parent;
		if (cmd.equals("Remove Parameter")) {
		    int index = pset.removeParameter(parameter);
		    treeModel.nodeRemoved(pset,index,parameter);
		    notifyParent(pset);
		}
	    }
	    else  if (parent instanceof Instance) {
		Instance instance = (Instance)parent;
		if (cmd.equals("Remove Parameter")) {
		    instance.removeUntrackedParameter(parameter);
		    confDbGUI.refreshParameters();
		}
	    }
	    
	}
	// regular parameter with PSet parent
	else if (parent instanceof PSetParameter) {
	    PSetParameter pset = (PSetParameter)parent;
	    if (cmd.equals("Remove Parameter")) {
		int index = pset.removeParameter(parameter);
		treeModel.nodeRemoved(pset,index,parameter);
		notifyParent(pset);
	    }
	}
	//untracked parameter
	else if (parent instanceof Instance) {
	    Instance instance = (Instance)parent;
	    if (cmd.equals("Remove Parameter")) {
		instance.removeUntrackedParameter(parameter);
		confDbGUI.refreshParameters();
	    }
	}
    }
	
    /** show dialog to add parameter to pset */
    private void addParameter(PSetParameter pset)
    {
       	AddParameterDialog dlg = new AddParameterDialog(frame,pset.isTracked());
	dlg.pack();
	dlg.setLocationRelativeTo(frame);
	dlg.setVisible(true);
	if (dlg.validChoice()) {
	    Parameter p =
		ParameterFactory.create(dlg.type(),
					dlg.name(),
					dlg.valueAsString(),
					dlg.isTracked(),
					false);
	    pset.addParameter(p);
	    treeModel.nodeInserted(pset,pset.parameterCount()-1);
	    notifyParent(pset);

	    TreePath treePath =new TreePath(treeModel.getPathToRoot(pset));
	    treeTable.getTree().expandPath(treePath);
	}
    }
	
    /** show dialog to add PSet to VPSet */
    private void addParameterSet(VPSetParameter vpset)
    {
	PSetParameter pset =
	    (PSetParameter)ParameterFactory.create("PSet",
						   "",
						   "",
						   vpset.isTracked(),
						   false);
	vpset.addParameterSet(pset);
	treeModel.nodeInserted(vpset,vpset.parameterSetCount()-1);
	notifyParent(vpset);
	
	TreePath treePath = new TreePath(treeModel.getPathToRoot(vpset));
	treeTable.getTree().expandPath(treePath);
    }
    
    /** notify parent instance of change */
    private void notifyParent(Parameter p)
    {
	Object parent = p.parent();

	while (parent != null) {
	    if (parent instanceof Reference) {
		Reference r = (Reference)parent;
		DatabaseEntry dbEntry = (DatabaseEntry)r.parent();
		dbEntry.setHasChanged();
		parent = null;
	    }
	    else if (parent instanceof DatabaseEntry) {
		DatabaseEntry dbEntry = (DatabaseEntry)parent;
		dbEntry.setHasChanged();
		parent = null;
	    }
	    else if (parent instanceof Parameter) {
		p = (Parameter)parent;
		parent = p.parent();
	    }
	    else {
		parent = null;
	    }
	}
    }
    
}
