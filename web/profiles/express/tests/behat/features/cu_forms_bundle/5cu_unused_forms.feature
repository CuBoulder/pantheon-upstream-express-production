@webform

Feature: Unused Forms Report
    Scenario Outline: An authenticated user with a role should be able to access the Unused forms report page
        Given I am logged in as a user with the <role> role
        When I go to "admin/reports/forms/unused"
        Then I should see <message>

        Examples:
            | role            | message        |
            | edit_my_content | "Unused Forms" |
            | edit_only       | "Unused Forms" |
            | site_editor     | "Unused Forms" |
            | site_owner      | "Unused Forms" |
            | administrator   | "Unused Forms" |
            | developer       | "Unused Forms" |

    Scenario: An anonymous user should not be able to access the Unused forms report page
        When I am on "admin/reports/forms/unused"
        Then I should see "Access denied"
