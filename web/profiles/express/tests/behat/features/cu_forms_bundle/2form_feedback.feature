@webform @feedback
Feature: Feedback Form places an existing Webform as a popup
In order to create a site feedback form
An authenticated user with the proper role
Should be able to select a published form as the site feedback form


#SOME ROLES CAN SELECT A FEEDBACK FORM AND SET OPTIONS FOR IT
 # @javascript IS THIS JS TAG NEEDED?
Scenario Outline: Access - Devs, Admins, SOs and ConMgrs can see all the options for the Feedback Form
 Given I am logged in as a user with the <role> role
 And am on "admin/settings/forms/feedback"
 Then I should see "Available Webforms"
 And I should see "Feedback Button Label"
 And I should see "Feedback Button Color"
 And I should see "Feedback Form Presentation"

Examples:
    | role            |
    | developer       |
    | administrator   |
    | site_owner      |
    | configuration_manager |
#  | forms_manager |

# SOME ROLES CAN NOT SELECT A FEEDBACK FORM
Scenario Outline: Access - Most roles cannot access feedback form settings
Given I am logged in as a user with the <role> role
And am on "admin/settings/forms/feedback"
Then I should see "Access denied"

Examples:
| role |
| edit_my_content  |
| site_editor      |
| edit_only        |
| access_manager   |

Scenario: Access - An anonymous user should not be able to access feedback form settings
 When I am on "admin/settings/forms/feedback"
Then I should see "Access denied"

@clean_install
Scenario: Functionality - Existing forms are available on the Feedback Form page; can be set
Given I am logged in as a user with the "site_owner" role
And am on "node/add/webform"
And fill in "Title" with "My Feedback Form"
And I press "Save"
And I go to "admin/settings/forms/feedback"
Then I should not see "There are no published webforms available"
And I select "My Feedback Form" from "edit-cu-feedback-path"
And I press "Save"
Then I should see "Settings have been updated"
