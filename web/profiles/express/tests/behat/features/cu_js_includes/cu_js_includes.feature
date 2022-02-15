@blocks @core
Feature: JS Inlcude
When I login to a Web Express website
As an authenticated user
I should be able to create, edit, and delete an include

# 1) TEST INCLUDE ADD PRIVILEGES
# 2) TEST THAT AN INCLUDE CAN BE CREATED AND REVISED
# 3) TEST THAT AN INCLUDE CAN BE DELETED


# 1) TEST INCLUDE ADD PRIVILEGES
Scenario Outline: Include Access: Some roles can add an Include
Given I am logged in as a user with the <role> role
When I go to "admin/content/js-includes/add"
Then I should see <message>

Examples:
| role                  | message                  |
| developer             | "Add AdmitHub Include" |
| administrator         | "Add AdmitHub Include" |
| site_owner            | "Add AdmitHub Include" |
| edit_my_content       | "Access denied"           |
| site_editor           | "Add AdmitHub Include" |
| edit_only             | "Access denied"            |

 Scenario: Include Access: An anonymous user cannot add a Text Block block
  When I am on "admin/content/js-includes/add"
  Then I should see "Access denied"

# 1.1) TEST INCLUDE ADD PRIVILEGES
Scenario Outline: Include Access: Some roles can add an AdmitHub Include
Given I am logged in as a user with the <role> role
When I go to "admin/content/js-includes/add/admithub"
Then I should see <message>

Examples:
| role                  | message                  |
| developer             | "Add AdmitHub Include" |
| administrator         | "Add AdmitHub Include" |
| site_owner            | "Add AdmitHub Include" |
| edit_my_content       | "Access denied"           |
| site_editor           | "Add AdmitHub Include" |
| edit_only             | "Access denied"            |

Scenario Outline: Include Access: Some roles can add an LiveChat Include
Given I am logged in as a user with the <role> role
When I go to "admin/content/js-includes/add/livechat"
Then I should see <message>

Examples:
| role                  | message                  |
| developer             | "Add LiveChat Include" |
| administrator         | "Add LiveChat Include" |
| site_owner            | "Add LiveChat Include" |
| edit_my_content       | "Access denied"           |
| site_editor           | "Add LiveChat Include" |
| edit_only             | "Access denied"            |

Scenario Outline: Include Access: Some roles can add an Slate Form Include
Given I am logged in as a user with the <role> role
When I go to "admin/content/js-includes/add/slateform"
Then I should see <message>

Examples:
| role                  | message                  |
| developer             | "Add Slate Form Include" |
| administrator         | "Add Slate Form Include" |
| site_owner            | "Add Slate Form Include" |
| edit_my_content       | "Access denied"           |
| site_editor           | "Add Slate Form Include" |
| edit_only             | "Access denied"            |

Scenario Outline: Block Access: Some roles can add an StatusPage Include
Given I am logged in as a user with the <role> role
When I go to "admin/content/js-includes/add/statuspage"
Then I should see <message>

Examples:
| role                  | message                  |
| developer             | "Add StatusPage Include" |
| administrator         | "Add StatusPage Include" |
| site_owner            | "Add StatusPage Include" |
| edit_my_content       | "Access denied"           |
| site_editor           | "Add StatusPage Include" |
| edit_only             | "Access denied"            |

# 2) TEST THAT AN ADMITHUB INCLUDE CAN BE CREATED
 Scenario: An AdmitHub include can be created.
 Given I am logged in as a user with the "site_owner" role
  And I am on "admin/content/js-includes/add/admithub"
  And fill in "edit-label" with "Test AdmitHub Include"
  And fill in "edit-account-id" with "123456789"
  When I press "edit-submit"
  Then I should be on "admin/content/js-includes"
 And I should see "Test AdmitHub Include"

#  2.5 CREATE REVISIONS TO THE BLOCK ABOVE
Scenario: Edit an Include
Given I am logged in as a user with the "site_owner" role
And I am on "admin/content/js-includes"
And I follow "Edit"
And fill in "edit-label" with "Test Edit AdmitHub Include"
 And I press "Save"
 Then I should see "Test Edit AdmitHub Include"

# 3) TEST THAT AN ADMITHUB INCLUDE CAN BE DELETED
Scenario: An AdmitHub include can be deleted.
Given I am logged in as a user with the "site_owner" role
And I am on "admin/content/js-includes"
And I follow "Edit"
And I press "Delete"
Then I should see "Do you really want to Delete the following includes?"
  And I press "Delete"
 Then I should not see "Test Edit AdmitHub Include"
