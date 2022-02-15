@cu_custom_logo
Feature: Add Custom Logo

    When I login to a Web Express website
    As an authenticated user with the right permission
    I should be able to add a custom logo

    Scenario Outline: An authenticated user should be able to access the form for adding a custom logo
        Given  I am logged in as a user with the <role> role
        When I go to "admin/config/user-interface/custom-logo"
        Then I should see <message>

        Examples:
            | role            | message         |
            | edit_my_content | "Access Denied" |
            | edit_only       | "Access Denied" |
            | site_owner      | "Access Denied" |
            | administrator   | "Access Denied" |
            | developer       | "Custom Logo"   |

    Scenario: An anonymous user should not be able to access the form for adding a custom logo
        When I am on "admin/config/user-interface/custom-logo"
        Then I should see "Access denied"
