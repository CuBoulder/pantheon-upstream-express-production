# Patches

### Patch: 1280930-description-50.patch  
Module: simplesamlphp_auth  
File Patched: simplesamlphp_auth.admin.inc  
Change Made: Add description to Simple SAML Auth Settings "Upon federated login, check if a local, pre-existing Drupal user is present with a username equal to the SAML authname ..."

### Patch: bean-integration-2127731-10.patch
Module: linkchecker  
File Patched: linkchecker/module/linkchecker_bean/ .info and .install and .module  
Change Made: create linkchecker_bean module as submodule of linkchecker  

### Patch file: content_menu-bigmenu-support-2054745-6.patch
Module: content_menu  

File Patched: content_menu.js  
Change:  Show menu item title input field when clicking on the trigger 

File Patched: content_menu.menu_admin.inc  
Change: Overhaul the menu_overview_form to improve menu authoring experience  

File Patched: content_menu.module  
Change: implement hood_form_FORM_ID_alter for the bigmenu overview form, if present 

File Patched: css/content_menu.css  
Change: colors and visibility  

### Patch: express-skip-slo-redirect.patch
Module: simplesamlphp_auth  
File Patched: simplesamlphp_auth.module  
Change Made: Add Express Custom Conditional "If simplesamlphp_auth_slo_redirect is set, then destroy the local session AND redirect to feadauth single logout page. Otherwise, destroy local session only and don't redirect "  

### Patch: insert-pathologic.patch
Module: insert  
File Patched: insert.module  
Change Made: change field widget settings from checkboxes to radio buttons; change widget settings styles; create URL  

### Patch: jquery.ui.dialog.patch.js
Module: views  
Change Made: jQuery bug fix; bug makes it impossible to scroll page when modal dialog is active. This JavaScript patch overwrites the $.ui.dialog.overlay.events object  

### Patch: missing-contextual-link.patch
Module: bean  
File Patched: bean.module  
Change Made: add contextual link to bean block  

### Patch file: pantheon-sso-dashboard-redirect.patch
Module: simplesamlphp_auth  
File Patched: simplesamlphp_auth.pages.inc  
Change Made: Redirect to admin/dashboard after logging in (this patches the patch 'simplesamlphp_auth-2476707-12e')

### Patch: simplesamlphp_auth-2476707-12.patch
Module: simplesamlphp_auth  
File Patched: simplesamlphp_auth.pages.inc  
Change Made: Require user to authenticated; then send them along
