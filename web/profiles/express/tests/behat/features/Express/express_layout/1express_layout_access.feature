@layout @core
Feature: CU Layout Access
  Developers should be able to modify layout settings.

Scenario Outline: The layout settings form should be available for certain roles.
  Given I am logged in as a user with the <role> role
  When I am on "admin/config/content/express-layout"
  Then I should not see <message>

  Examples:
    | role            | message         |
    | edit_only       | "Select which regions are available to place blocks for each content type." |
    | edit_my_content | "Select which regions are available to place blocks for each content type." |
    | site_editor     | "Select which regions are available to place blocks for each content type." |
    | site_owner      | "Select which regions are available to place blocks for each content type." |
    | administrator   | "Select which regions are available to place blocks for each content type." |
    | developer       | "Access denied" |

Scenario: Adding or removing regions on settings form should be reflected on node layout forms
  Given I am logged in as a user with the "developer" role
    And I go to "admin/config/content/express-layout"
    And I check "edit-page-field-content-bottom"
    And I uncheck "edit-page-field-post-title"
    And I press "Save Layout Settings"
    And I go to "node/1"
    And I follow "Edit Layout"
  Then I should see an "#edit-field-content-bottom" element
    And I should not see an "#edit-field-post-title" element
# And now put them back the way they were
  When I go to "admin/config/content/express-layout"
    And I uncheck "edit-page-field-content-bottom"
    And I check "edit-page-field-post-title"
    And I press "Save Layout Settings"
    And I go to "node/1"
    And I follow "Edit Layout"
  Then I should not see an "#edit-field-content-bottom" element
    And I should see an "#edit-field-post-title" element
