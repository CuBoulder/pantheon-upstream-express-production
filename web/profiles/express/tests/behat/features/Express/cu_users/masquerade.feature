@users @masquerade @core
Feature: Masquerade module
When I am on the User pages
As an authenticated user with the proper role
I can masquerade as other users

## cannot masquerade as user 1
## can masquerade as crafts


Scenario Outline: A functional Masquerade switch button appears on user view page
  Given I am logged in as a user with the <role> role
  And I am on "admin/people"
  And I fill in "edit-combine" with "site_owner"
  And I press "Apply"
  Then I should see "site_owner"
  And I follow "edit"
  And I follow "View"
  Then I should see "Masquerade as site_owner"
  When I follow "Masquerade as site_owner"
  Then I should see "You are now masquerading as site_owner"
  And I should see the link "Switch Back"
  And I follow "Switch Back"
  Then I should be on "admin/dashboard"
  And I should see "You are no longer masquerading as site_owner"

  Examples:
    | role             |
    | administrator    |
    | developer      |


  Scenario: User/1 cannot be masqueraded as by a developer
    Given I am logged in as a user with the "developer" role
    And I am on "user/1"
    Then I should see "Masquerade as admin-"
    When I follow "Masquerade as admin-"
    Then I should see "Access denied"


  Scenario Outline: User/1 cannot be masqueraded as by any other role
    Given I am logged in as a user with the <role> role
    And I am on "user/1"
    Then I should see "Access denied"

    Examples:
      | role             |
      | administrator    |
      | site_owner      |
      | site_editor      |
      | edit_only      |
      | edit_my_content      |

Scenario: Masquerade admins are configured properly
  Given I am logged in as a user with the "developer" role
  And I am on "admin/config/people/masquerade"
  Then the "administrator" checkbox should be checked
  And the "developer" checkbox should be checked

 Scenario Outline: Most roles cannot access the Masquerade configuration page
   Given I am logged in as a user with the <role> role
   And I go to "admin/config/people/masquerade"
   Then I should see "Access denied"

   Examples:
     | role             |
     | administrator    |
     | site_owner      |
     | site_editor      |
     | edit_only      |
     | edit_my_content      |

